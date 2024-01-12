/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 21:35:07 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/06 21:35:28 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	out = malloc(i + j + 1);
	if (!out)
		return (0);
	out[i + j] = 0;
	while (j--)
		out[i + j] = (char)s2[j];
	while (i--)
		out[i] = (char)s1[i];
	return (out);
}
