/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 13:26:06 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:43:09 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	print_params(void)
{
	ft_printf("You can give any settings files or parameters as arguments.\n");
}

int	main(int argc, char **argv)
{
	t_screenstate	state;
	mlx_t			*mlx;
	mlx_image_t		*img;

	if (argc == 1)
		print_params();
	ft_strlcpy(argv[0], "standard", 9);
	state = read_args(argv);
	mlx = mlx_init(state.camera.width, state.camera.height, "fract_ol", true);
	if (!mlx)
		ft_exit(1, __func__, __LINE__);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_exit(1, __func__, __LINE__);
	draw_fract(img, state.camera, state.fractal);
	state.mlx = mlx;
	state.img = img;
	mlx_scroll_hook(mlx, &ft_scroll_hook, &state);
	mlx_resize_hook(mlx, &ft_resize_hook, &state);
	mlx_key_hook(mlx, &ft_key_hook, &state);
	mlx_close_hook(mlx, &ft_close_hook, &state);
	mlx_loop_hook(mlx, &ft_loop_hook, &state);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return ((void)argc, EXIT_SUCCESS);
}
