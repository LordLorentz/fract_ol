/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 20:33:27 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/11 15:54:17 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	size_t	bitsize_total;
	void	*out;

	total = nmemb * size;
	bitsize_total = 0;
	while (nmemb)
	{
		nmemb = nmemb >> 1;
		bitsize_total++;
	}
	while (size)
	{
		size = size >> 1;
		bitsize_total++;
	}
	if (bitsize_total > 40 && total != 0)
		return (0);
	out = malloc(total);
	if (!out)
		return (0);
	ft_bzero(out, total);
	return (out);
}
