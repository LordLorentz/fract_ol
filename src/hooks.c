/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 13:40:13 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:50:40 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_resize_hook(int32_t width, int32_t height, void *param)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_cam			cam;
	t_fractal		fractal;

	mlx = ((t_screenstate *)param)->mlx;
	img = ((t_screenstate *)param)->img;
	cam = ((t_screenstate *)param)->camera;
	fractal = ((t_screenstate *)param)->fractal;
	mlx_delete_image(mlx, img);
	img = mlx_new_image(mlx, width, height);
	if (!img)
		ft_exit(1, __func__, __LINE__);
	draw_fract(img, cam, fractal);
	mlx_image_to_window(mlx, img, 0, 0);
	((t_screenstate *)param)->mlx = mlx;
	((t_screenstate *)param)->img = img;
	((t_screenstate *)param)->camera = cam;
	((t_screenstate *)param)->fractal = fractal;
}

void	ft_scroll_hook(double dx, double dy, void *param)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_cam			cam;
	t_fractal		fractal;

	mlx = ((t_screenstate *)param)->mlx;
	img = ((t_screenstate *)param)->img;
	cam = ((t_screenstate *)param)->camera;
	fractal = ((t_screenstate *)param)->fractal;
	(void)dx;
	zoom_to_cursor(mlx, &cam, dy);
	draw_fract(img, cam, fractal);
	((t_screenstate *)param)->mlx = mlx;
	((t_screenstate *)param)->img = img;
	((t_screenstate *)param)->camera = cam;
	((t_screenstate *)param)->fractal = fractal;
}

void	ft_loop_hook(void *param)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_cam			cam;
	t_fractal		fractal;
	int				draw;

	mlx = ((t_screenstate *)param)->mlx;
	img = ((t_screenstate *)param)->img;
	cam = ((t_screenstate *)param)->camera;
	fractal = ((t_screenstate *)param)->fractal;
	draw = 0;
	draw += check_arrow_keys(mlx, &cam);
	draw += check_wasd(mlx, &fractal);
	draw += check_qert(mlx, &fractal);
	draw += check_other((t_screenstate *)param, &cam);
	if (draw)
		draw_fract(img, cam, fractal);
	((t_screenstate *)param)->mlx = mlx;
	((t_screenstate *)param)->img = img;
	((t_screenstate *)param)->camera = cam;
	((t_screenstate *)param)->fractal = fractal;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	char	*filename;

	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_PRESS)
	{
		ft_printf("Enter filename to output state to: ");
		filename = ft_strcull(get_next_line(1), &ft_isspace);
		output_state((t_screenstate *) param, filename);
		free(filename);
	}
}

void	ft_close_hook(void *param)
{
	ft_printf("Shutting down...\n");
	output_state((t_screenstate *) param, "latest");
	exit(0);
}
