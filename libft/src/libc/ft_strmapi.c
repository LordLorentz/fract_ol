/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 21:37:46 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/07 12:35:01 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	out = ft_strdup((const char *)s);
	if (!out)
		return (0);
	i = 0;
	while (out[i])
	{
		out[i] = (*f)(i, out[i]);
		i++;
	}
	return (out);
}
