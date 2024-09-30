/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 13:40:13 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 20:54:27 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_resize_hook(int32_t width, int32_t height, t_screenstate *state)
{
	join_draw_threads(state);
	mlx_delete_image(state->mlx, state->img);
	state->img = mlx_new_image(state->mlx, width, height);
	if (!state->img)
		ft_exit(1, __func__, __LINE__);
	mlx_image_to_window(state->mlx, state->img, 0, 0);
	create_draw_threads(state);
}

void	ft_scroll_hook(double dx, double dy, t_screenstate *state)
{
	(void)dx;
	zoom_to_cursor(state->mlx, &state->camera, dy);
	draw_cycle(state);
}

void	ft_loop_hook(t_screenstate *state)
{
	int				draw;

	draw = 0;
	draw += check_arrow_keys(state->mlx, &state->camera);
	draw += check_wasd(state->mlx, &state->fractal);
	draw += check_qert(state->mlx, &state->fractal);
	draw += check_other(state, &state->camera);
	if (draw)
		draw_cycle(state);
}

void	ft_close_hook(t_screenstate *state)
{
	ft_printf("Shutting down...\n");
	output_state(state, "latest");
	exit(0);
}
