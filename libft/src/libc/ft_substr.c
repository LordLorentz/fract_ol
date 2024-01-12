/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 13:03:03 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/10 22:02:06 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*out;

	i = 0;
	while (s[i])
		i++;
	if (start > i)
		return (ft_calloc(1, 1));
	i = 0;
	while (s[i + start] && i < (unsigned int)len)
		i++;
	out = malloc(i + 1);
	out[i] = 0;
	while (i--)
		out[i] = (char)s[start + i];
	return (out);
}
