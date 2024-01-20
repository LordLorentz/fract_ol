/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _read_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 22:15:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/18 12:36:17 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_gc	*read_fractal(char *line)
{
	if (ft_strncmp(line, "julia_2", 7) == 0)
		return (&gc_j_2);
	if (ft_strncmp(line, "mbrot_2", 7) == 0)
		return (&gc_b_2);
	if (ft_strncmp(line, "julia_3", 7) == 0)
		return (&gc_j_3);
	if (ft_strncmp(line, "mbrot_3", 7) == 0)
		return (&gc_b_3);
	if (ft_strncmp(line, "julia_g", 7) == 0)
		return (&gc_j_g);
	if (ft_strncmp(line, "mbrot_g", 7) == 0)
		return (&gc_b_g);
	if (ft_strncmp(line, "julia_n", 7) == 0)
		return (&gc_j_n);
	if (ft_strncmp(line, "mbrot_n", 7) == 0)
		return (&gc_b_n);
	if (ft_strncmp(line, "julia_t", 7) == 0)
		return (&gc_j_t);
	if (ft_strncmp(line, "mbrot_t", 7) == 0)
		return (&gc_b_t);
	if (ft_strncmp(line, "julia_x", 7) == 0)
		return (&gc_j_x);
	if (ft_strncmp(line, "mbrot_x", 7) == 0)
		return (&gc_b_x);
	ft_exit(1, __func__, __LINE__);
	return (NULL);
}

t_occ	*read_occlusion(char *line)
{
	if (ft_strncmp(line, "cutoff", 6) == 0)
		return (&occ_cutoff);
	if (ft_strncmp(line, "substraction", 12) == 0)
		return (&occ_sub);
	if (ft_strncmp(line, "angle", 5) == 0)
		return (&occ_angle);
	if (ft_strncmp(line, "depth", 5) == 0)
		return (&occ_depth);
	if (ft_strncmp(line, "plane", 5) == 0)
		return (&occ_plane);
	if (ft_strncmp(line, "beam", 4) == 0)
		return (&occ_beam);
	if (ft_strncmp(line, "recursive", 9) == 0)
		return (&occ_curse);
	ft_exit(1, __func__, __LINE__);
	return (NULL);
}

int	parse_line(char *line, t_screenstate *state)
{
	if (ft_strncmp(line, "fractal=", 8) == 0)
		return (state->fractal.get_color = read_fractal(line + 8), 0);
	if (ft_strncmp(line, "c.real=", 7) == 0)
		return (state->fractal.c.real = ft_atod(line + 7), 0);
	if (ft_strncmp(line, "c.imgn=", 7) == 0)
		return (state->fractal.c.imgn = ft_atod(line + 7), 0);
	if (ft_strncmp(line, "symmetry=", 9) == 0)
		return (state->fractal.symmetry = ft_atod(line + 9), 0);
	if (ft_strncmp(line, "depth=", 6) == 0)
		return (state->fractal.depth = ft_atoi(line + 6), 0);
	if (ft_strncmp(line, "occlusion=", 10) == 0)
		return (state->camera.occlusion = read_occlusion(line + 10), 0);
	if (ft_strncmp(line, "zoom=", 5) == 0)
		return (state->camera.zoom = ft_atod(line + 5), 0);
	if (ft_strncmp(line, "x_offset=", 9) == 0)
		return (state->camera.x_offset = ft_atoi(line + 9), 0);
	if (ft_strncmp(line, "y_offset=", 9) == 0)
		return (state->camera.y_offset = ft_atoi(line + 9), 0);
	if (ft_strncmp(line, "width=", 6) == 0)
		return (state->camera.width = ft_atoi(line + 6), 0);
	if (ft_strncmp(line, "height=", 7) == 0)
		return (state->camera.height = ft_atoi(line + 7), 0);
	return (1);
}

t_screenstate	read_args(char **in)
{
	t_screenstate	state;
	int				i;
	int				fd;
	char			*line;

	i = -1;
	while (in[++i])
	{
		if (parse_line(ft_strcull(in[i], &ft_isspace), &state) == 0)
			continue ;
		fd = open(ft_strcull(in[i], &ft_isspace), O_RDONLY);
		if (fd < 2)
			ft_exit(fd, __func__, __LINE__);
		while (true)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			if (parse_line(ft_strcull(line, &ft_isspace), &state))
				ft_exit(-3, __func__, __LINE__);
			free(line);
		}
	}
	return (state);
}
