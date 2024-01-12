/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmods.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 11:20:33 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/07 11:21:44 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)0;
		i++;
	}
}
