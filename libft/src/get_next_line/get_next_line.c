/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 20:52:58 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/11 14:15:49 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*f_str(const char *src, char *dst, size_t n, int mode);
t_dict	*f_dict(t_dict **dict, void *content, int ndx, int mode);

t_dict	*exp_buf(int fd, int ndx, t_dict *out);
char	*sftln(t_dict *buffer, int fd, char *dst, size_t size);
t_dict	**find_rm_index(t_dict **dict, int index, int mode);

char	*get_next_line(int fd)
{
	static t_dict	*files = 0;
	t_dict			**buffer;
	char			*out;

	if (BFSZ <= 0)
		return (0);
	buffer = find_rm_index(&files, fd, 1);
	if (!*buffer)
		return ((char *)(0 * (size_t)f_dict(&files, 0, 0, 3)));
	if (f_str((*buffer)->cnt, "\n", 0, 1) == 0)
		*buffer = exp_buf(fd, (*buffer)->ndx, *buffer);
	out = sftln(*buffer, fd, 0, 0);
	*buffer = f_dict(buffer, 0, 0, 1);
	if (out && *out)
		return (out);
	if (!out)
		return ((char *)(0 * (size_t)f_dict(&files, 0, 0, 3)));
	f_dict(buffer, 0, 0, 2);
	*buffer = 0;
	find_rm_index(&files, fd, 0);
	free(out);
	return (0);
}
