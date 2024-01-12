/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 21:43:12 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/06 21:45:26 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*out;

	i = 0;
	while (s[i])
		i++;
	out = malloc(++i);
	if (!out)
		return (0);
	while (--i >= 0)
		out[i] = (char)s[i];
	return (out);
}
