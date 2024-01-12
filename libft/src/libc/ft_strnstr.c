/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:23:30 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/10 21:24:46 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != 0 && i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *)big + i);
		i++;
	}
	j = 0;
	while (big[i + j] == little[j] && little[j] != 0 && i + j < len)
		j++;
	if (little[j] == 0)
		return ((char *)big + i);
	return (0);
}
