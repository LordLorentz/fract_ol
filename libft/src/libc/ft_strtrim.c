/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:55:09 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/11 15:07:58 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		offset;
	char	*out;

	offset = 0;
	while (s1[offset] && ft_strchr(set, s1[offset]))
		offset++;
	size = 0;
	while (s1[size + offset])
		size++;
	if (!size)
		return (ft_calloc(1, 1));
	while (size > 0 && ft_strchr(set, s1[size + offset - 1]))
		size--;
	out = malloc(size + 1);
	if (!out)
		return (0);
	out[size] = 0;
	while (size-- > 0)
		out[size] = s1[size + offset];
	return (out);
}
