/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcull.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 13:42:32 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 14:49:01 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strcull(char *str, int (*f)(int))
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	while (str[i + offset] != '\0')
	{
		while (str[i + offset] != '\0' && f(str[i + offset]))
			offset++;
		str[i] = str[i + offset];
		if (str[i] == '\0')
			break ;
		i++;
	}
	str[i] = '\0';
	return (str);
}
