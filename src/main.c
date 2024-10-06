/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 13:26:06 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 20:41:06 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_screenstate	state;

	ft_strlcpy(argv[0], "standard", 9);
	state = read_args(argv);
	if (argc == 1 || check_state(state) == 1)
		print_params();
	state.mlx = mlx_init(state.camera.width, state.camera.height, "fract_ol", true);
	if (!state.mlx)
		ft_exit(1, __func__, __LINE__);
	state.img = mlx_new_image(state.mlx, state.mlx->width, state.mlx->height);
	if (!state.img || (mlx_image_to_window(state.mlx, state.img, 0, 0) < 0))
		ft_exit(1, __func__, __LINE__);
	output_nonblocking(&state);
	initialize_threadstate(&state);
	create_draw_threads(&state);
	mlx_scroll_hook(state.mlx, (mlx_scrollfunc)&ft_scroll_hook, &state);
	mlx_resize_hook(state.mlx, (mlx_resizefunc)&ft_resize_hook, &state);
	mlx_close_hook(state.mlx, (mlx_closefunc)&ft_close_hook, &state);
	mlx_loop_hook(state.mlx, (t_loop)&ft_loop_hook, &state);
	mlx_loop(state.mlx);
	mlx_terminate(state.mlx);
	exit(EXIT_SUCCESS);
}
