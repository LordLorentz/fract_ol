/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 11:20:33 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/10 21:12:28 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (dest > src)
		sign = -1;
	if (sign == -1)
		i = (int)n - 1;
	while ((i < (int)n && sign == 1) || (i >= 0 && sign == -1))
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i += sign;
	}
	return (dest);
}
