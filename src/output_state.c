/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_state.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 13:22:40 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 17:15:34 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	output_state(t_screenstate state)
{
	const char		*filename = get_next_line(1);
	const int		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	const t_fractal	fractal = state.fractal;
	const t_cam		camera = state.camera;
	char			*temp;
	
	if (fd < 2)
		ft_exit(fd, __func__, __LINE__);
	temp = "GET_FRACTAL";
	ft_fprintf(fd,
		"fractal=%s\nc.real=%lf\nc.imgn=%lf\nsymmetry=%lf\ndepth=%ld\n",
		temp, fractal.c.real, fractal.c.imgn, fractal.symmetry, fractal.depth);
	temp = "GET_OCCLUSION";
	ft_fprintf(fd,
		"occlusion=%s\nzoom=%lf\nx_offset=%d\ny_offset=%d\n",
		temp, camera.zoom, camera.x_offset, camera.y_offset);
	ft_fprintf(fd,
		"width=%d\nheight=%d\n",
		state.mlx->width, state.mlx->height);
}

void	output_lock(t_screenstate state)
{
	static int	lock = false;

	if (lock == false)
	{
		lock = true;
		output_state(state);
		lock = false;
	}
}
