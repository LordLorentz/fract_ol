/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcull.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 13:42:32 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 13:47:43 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strcull(char *str, int (*f)(int))
{
	int i;
	int offset;

	offset = 0;
	i = 0;
	while (str[i + offset])
	{
		while (f(str[i]))
			offset++;
		str[i] = str[i + offset];
	}
	str[i] = '\0';
	return (str);
}
