/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 15:01:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:45:55 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

//Maintains fractal x and y values for target x and y values
inline void	zoom(t_cam *cam, double factor, double target_x, double target_y)
{
	const double	fract_x = (target_x + cam->x_offset) * cam->zoom * JUST;
	const double	fract_y = (target_y + cam->y_offset) * cam->zoom * JUST;

	cam->zoom *= factor;
	cam->x_offset = fract_x / (cam->zoom * JUST) - target_x;
	cam->y_offset = fract_y / (cam->zoom * JUST) - target_y;
}

void	zoom_to_cursor(mlx_t *mlx, t_cam *cam, double direction)
{
	double	factor;
	int32_t	x;
	int32_t	y;

	if (direction > 0)
		factor = ZOOM_CONST;
	if (direction < 0)
		factor = 1 / ZOOM_CONST;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		factor = pow(factor, FASTSCROLL);
	mlx_get_mouse_pos(mlx, &x, &y);
	zoom(cam, factor, (double)x, (double)y);
}
