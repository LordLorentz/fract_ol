/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 15:01:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:44:25 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	check_arrow_keys(mlx_t *mlx, t_cam *cam)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		dx = -1;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		dx = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		dy = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		dy = -1;
	dx = dx + (FASTSCROLL - 1) * dx * mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT);
	dy = dy + (FASTSCROLL - 1) * dy * mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT);
	dx = dx - (1.0 - 1.0 / SLOWSCROLL) * dx * mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL);
	dy = dy - (1.0 - 1.0 / SLOWSCROLL) * dy * mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL);
	if (dx == 0 && dy == 0)
		return (0);
	cam->x_offset += dx;
	cam->y_offset += dy;
	return (1);
}

int	check_wasd(mlx_t *mlx, t_fractal *fractal)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		dx = -0.001;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		dx = 0.001;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		dy = 0.001;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		dy = -0.001;
	dx = dx + (FASTSCROLL - 1) * dx * mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT);
	dy = dy + (FASTSCROLL - 1) * dy * mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT);
	dx = dx - (1.0 - 1.0 / SLOWSCROLL) * dx * mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL);
	dy = dy - (1.0 - 1.0 / SLOWSCROLL) * dy * mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL);
	if (dx == 0 && dy == 0)
		return (0);
	fractal->c.real += dx;
	fractal->c.imgn += dy;
	return (1);
}

int	check_qert(mlx_t *mlx, t_fractal *fractal)
{
	double	dx;
	long	dy;

	dx = 0;
	dy = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_Q))
		dx = -0.01;
	if (mlx_is_key_down(mlx, MLX_KEY_E))
		dx = 0.01;
	if (mlx_is_key_down(mlx, MLX_KEY_R))
		dy = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_T))
		dy = -1;
	dx = dx + (FASTSCROLL - 1) * dx * mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT);
	dy = dy + (FASTSCROLL - 1) * dy * mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT);
	dx = dx - (1.0 - 1.0 / SLOWSCROLL) * dx * mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL);
	dy = dy - (1.0 - 1.0 / SLOWSCROLL) * dy * mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL);
	if (dx == 0 && dy == 0)
		return (0);
	fractal->symmetry += dx;
	fractal->depth += dy;
	if (fractal->depth < 1)
		fractal->depth = 1;
	return (1);
}

int	check_other(t_screenstate *state, t_cam *camera)
{
	int	draw;

	draw = 0;
	if (mlx_is_key_down(state->mlx, MLX_KEY_SPACE))
	{
		ft_printf("Symmetry: %f\n", state->fractal.symmetry);
		ft_printf("Depth: %d\n", (int)state->fractal.depth);
		ft_printf("Zoom: %f\n", state->camera.zoom);
		ft_printf("Julia X: %f, Julia Y: %f\n",
			state->fractal.c.real, state->fractal.c.imgn);
	}
	if (mlx_is_key_down(state->mlx, MLX_KEY_Z))
	{
		camera->zoom = 1;
		camera->x_offset = -state->mlx->width / 2;
		camera->y_offset = -state->mlx->height / 2;
		draw++;
	}
	if (mlx_is_key_down(state->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("Shutting down...\n");
		output_state(state, "latest");
		exit(0);
	}
	return (draw);
}
