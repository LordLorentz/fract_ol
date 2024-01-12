/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 20:52:56 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/11 14:15:49 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//mode 0: returns strlen of src
//mode 1: strnchr of src and *dst, or strchr if n = 0
//mode 2: strlcpy of src and dst, or strcpy if n = 0, nulls end in both cases
//mode 3: strcpy without copying the \0
char	*f_str(const char *src, char *dst, size_t n, int mode)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < n - 1 || !n))
	{
		if (mode == 1 && src[i] == *dst)
			return ((char *)src + i);
		if (mode == 2 || mode == 3)
			dst[i] = src[i];
		i++;
	}
	if (mode == 0)
		return ((char *)i);
	if (mode == 1 && src[i] == *dst)
		return ((char *)src + i);
	if (mode == 2)
		dst[i] = '\0';
	return (0);
}

//content = (void *)f_dict(dict->nxt, 0, 0, mode);
//necessary because otherwise I can't pass the output of mode 1 down the stack

//mode 0: new dict
//mode 1: free() all entries except the last, which is returned.
//mode 2: free() all entries
//mode 3: uses mode 2 to free the content of each entry (and frees all entries) 
t_dict	*f_dict(t_dict **dict, void *content, int ndx, int mode)
{
	if (mode == 0)
	{
		if (!content)
			return (0);
		*dict = malloc(sizeof(t_dict));
		if (!dict)
			free(content);
		if (!dict)
			return (0);
		(*dict)->cnt = content;
		(*dict)->ndx = ndx;
		(*dict)->nxt = 0;
		return (*dict);
	}
	if (!(*dict)->nxt && mode == 1)
		return (*dict);
	if ((*dict)->nxt)
		content = (void *)f_dict(&(*dict)->nxt, 0, 0, mode);
	if (mode == 3)
		f_dict((t_dict **)&(*dict)->cnt, 0, 0, 2);
	free((*dict)->cnt);
	free(*dict);
	*dict = 0;
	return ((t_dict *)content);
}

//Yes, I recycle my *out variable.
//new mode: creates and fills a buffer using the file descriptor and size index
//complete mode: completes the input buffer
t_dict	*exp_buf(int fd, int ndx, t_dict *out)
{
	ssize_t	rdsz;
	ssize_t	i;
	ssize_t	insz;

	if (!out)
	{
		out = malloc((BFSZ << ndx) + 1);
		if (!out)
			return (0);
		out = f_dict(&out, out, ndx, 0);
		if (!out)
			return (0);
		*(char *)out->cnt = 0;
	}
	insz = (ssize_t)f_str(out->cnt, 0, 0, 0);
	i = insz / BFSZ;
	insz = insz % BFSZ;
	rdsz = BFSZ;
	while (rdsz == BFSZ && i + !!insz < 1 << ndx
		&& (!i || !f_str(out->cnt + insz + BFSZ * (i - 1), "\n", BFSZ, 1)))
		rdsz = read(fd, out->cnt + insz + BFSZ * i++, BFSZ);
	((char *)out->cnt)[(insz + rdsz + BFSZ * (i - 1)) * (rdsz != -1)] = '\0';
	((char *)out->cnt)[BFSZ << ndx] = 42 * !(rdsz == BFSZ);
	return (out);
}
//printf("-_-_ndx: %3d, rdsz: %3lu, insz: %3lu, i: %3lu, buf: %s\n", ndx, rdsz,
//  insz, i, (char *)out->cnt);

//if (!src && (long)f_str(buffer->cnt, 0, 0, 0) == BFSZ << buffer->ndx)
//checking to see wether eof has been reached
char	*sftln(t_dict *buffer, int fd, char *dst, size_t size)
{
	char	*src;

	src = f_str(buffer->cnt, "\n", 0, 1);
	if (!src && !((char *)buffer->cnt)[BFSZ << buffer->ndx])
	{
		buffer->nxt = exp_buf(fd, buffer->ndx + 1, 0);
		if (!buffer->nxt)
			return (0);
		dst = sftln(buffer->nxt, fd, dst, size
				+ (size_t)f_str(buffer->cnt, 0, 0, 0));
		if (!dst)
			return (0);
		f_str(buffer->cnt, dst + size, 0, 3);
	}
	else
	{
		if (!src++)
			src = f_str(buffer->cnt, "\0", 0, 1);
		dst = malloc(size + (size_t)src - (size_t)buffer->cnt + 1);
		if (!dst)
			return (NULL);
		f_str(buffer->cnt, dst + size, (size_t)src -(size_t)buffer->cnt + 1, 2);
		f_str(src, buffer->cnt, 0, 2);
	}
	return (dst);
}

//mode 0: remove the entry corresponding to index, without freeing its content
//mode 1: return the content of the entry corresponding to index,
//creating it if it does not exist
t_dict	**find_rm_index(t_dict **dict, int index, int mode)
{
	t_dict	*out;

	if (*dict == NULL)
	{
		if (mode == 0)
			return (NULL);
		out = exp_buf(index, 0, 0);
		if (out == NULL)
			return (0);
		*dict = f_dict(dict, out, index, 0);
		if (*dict == NULL)
			return (0);
		return ((t_dict **)&(*dict)->cnt);
	}
	if ((*dict)->ndx == index)
	{
		if (mode == 1)
			return ((t_dict **)&(*dict)->cnt);
		out = *dict;
		*dict = out->nxt;
		free(out);
		return (NULL);
	}
	return (find_rm_index(&(*dict)->nxt, index, mode));
}
