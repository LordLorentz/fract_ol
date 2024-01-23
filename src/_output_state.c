/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _output_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 13:22:40 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/23 13:58:08 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char	*get_fractal(t_gc *f)
{
	if (f == &gc_j_2)
		return ("julia_2");
	if (f == &gc_b_2)
		return ("mbrot_2");
	if (f == &gc_j_3)
		return ("julia_3");
	if (f == &gc_b_3)
		return ("mbrot_3");
	if (f == &gc_j_g)
		return ("julia_g");
	if (f == &gc_b_g)
		return ("mbrot_g");
	if (f == &gc_j_n)
		return ("julia_n");
	if (f == &gc_b_n)
		return ("mbrot_n");
	if (f == &gc_j_t)
		return ("julia_t");
	if (f == &gc_b_t)
		return ("mbrot_t");
	if (f == &gc_j_x)
		return ("julia_x");
	if (f == &gc_b_x)
		return ("mbrot_x");
	return ("Error!");
}

char	*get_occlusion(t_occ *f)
{
	if (f == &occ_cutoff)
		return ("cutoff");
	if (f == &occ_sub)
		return ("substraction");
	if (f == &occ_angle)
		return ("angle");
	if (f == &occ_depth)
		return ("depth");
	if (f == &occ_plane)
		return ("plane");
	if (f == &occ_beam)
		return ("beam");
	if (f == &occ_curse)
		return ("recursive");
	return ("Error!");
}

void	output_state(t_screenstate *state, char *filename)
{
	int				fd;
	const t_fractal	fractal = state->fractal;
	const t_cam		cam = state->camera;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 2)
		ft_exit(fd, __func__, __LINE__);
	ft_fprintf(fd,
		"fractal=%s\nc.real=%f\nc.imgn=%f\nsymmetry=%f\ndepth=%l\n",
		get_fractal(fractal.get_color), fractal.c.real, fractal.c.imgn,
		fractal.symmetry, fractal.depth);
	ft_fprintf(fd,
		"occlusion=%s\nzoom=%f\nx_offset=%l\ny_offset=%l\n",
		get_occlusion(cam.occlusion), cam.zoom, cam.x_offset, cam.y_offset);
	ft_fprintf(fd,
		"width=%d\nheight=%d\n",
		state->mlx->width, state->mlx->height);
	close(fd);
}
