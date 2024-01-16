/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _read_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 22:15:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/16 23:00:25 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	parse_line(char *line, t_screenstate *state)
{
	
}

t_screenstate	read_args(char **in, mlx_t *mlx, mlx_image_t *img)
{
	t_screenstate	state;
	int				i;
	int				fd;
	char			*line;

	state.mlx = mlx;
	state.img = img;
	i = -1;
	while (in[i++])
	{
		if (parse_line(in[i], &state) == 0)
			continue ;
		fd = open(in[i], O_RDONLY);
		if (fd < 2)
			ft_exit(fd, __func__, __LINE__);
		while (true)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			parse_line(line, &state);
			free(line);
		}
	}
	return (state);
}
