/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 13:26:06 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/16 21:57:51 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_cam			cam;
	t_fractal		fractal;
	t_screenstate	state;

	mlx = mlx_init(WIDTH, HEIGHT, "fract_ol", true);
	if (!mlx)
		ft_exit(1, __func__, __LINE__);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_exit(1, __func__, __LINE__);
	fractal.get_color = &gc_b_n;
	fractal.symmetry = 2.0;
	fractal.c.real = 0.274;
	fractal.c.imgn = -0.008;
	fractal.depth = DEPTH;
	cam.x_offset = - WIDTH / 2;
	cam.y_offset = - HEIGHT / 2;
	cam.zoom = 1;
	cam.occlusion = &occ_sub;
	draw_fract(img, cam, fractal);
	state.camera = cam;
	state.fractal = fractal;
	state.mlx = mlx;
	state.img = img;
	mlx_scroll_hook(mlx, &ft_scroll_hook, &state);
	mlx_resize_hook(mlx, &ft_resize_hook, &state);
	mlx_key_hook(mlx, &ft_key_hook, &state);
	mlx_loop_hook(mlx, &ft_loop_hook, &state);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
