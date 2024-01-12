/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:13:50 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/23 21:47:45 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_str_amt(char *s, char c)
{
	int	flag;
	int	out;

	out = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c && flag)
		{
			flag = 0;
			out++;
		}
		if (*s != c)
			flag = 1;
		s++;
	}
	out += flag;
	return (out);
}

static void	find_str_sizes(char *s, char c, size_t *out)
{
	int		flag;
	size_t	size;

	flag = 0;
	size = 0;
	while (*s)
	{
		if (*s == c && flag)
		{
			flag = 0;
			*out++ = size;
			size = 0;
		}
		if (*s != c)
		{
			flag = 1;
			size++;
		}
		s++;
	}
	if (flag)
		*out = size;
}

static void	fill_strs(char *s, char c, char **out)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (*s)
	{
		if (*s == c && flag)
		{
			flag = 0;
			out[0][i] = 0;
			i = 0;
			out++;
		}
		if (*s != c)
		{
			flag = 1;
			out[0][i] = *s;
			i++;
		}
		s++;
	}
	if (flag)
		out[0][i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		amt;
	char	**out;

	amt = find_str_amt((char *)s, c);
	out = malloc((amt + 1) * sizeof(size_t));
	if (!out)
		return (0);
	out[amt] = 0;
	find_str_sizes((char *)s, c, (size_t *)out);
	i = 0;
	while (out[i])
	{
		out[i] = malloc(((size_t)out[i] + 1) * sizeof(char));
		if (!out[i++])
			return ((char **)free_ptr_arr((void **)out));
	}
	fill_strs((char *)s, c, out);
	return (out);
}
