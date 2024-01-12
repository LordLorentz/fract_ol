/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 14:21:00 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/06 21:36:49 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstend;

	dstend = 0;
	while (dst[dstend] && dstend < size)
		dstend++;
	if (dstend == size)
		return (dstend + ft_strlen((char *)src));
	i = 0;
	while (src[i] && dstend + i < size - 1)
	{
		dst[dstend + i] = src[i];
		i++;
	}
	dst[size - 1] = 0;
	return (dstend + ft_strlen((char *)src));
}
