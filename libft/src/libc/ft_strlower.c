/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlower.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/22 20:56:55 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/22 20:59:14 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
