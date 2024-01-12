/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arr_cat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 21:27:38 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/13 14:38:56 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arr_cat(char **in, const char *last, int out_size, char **out)
{
	int		out_pos;
	int		i;

	*out = malloc((out_size + 1) * sizeof(char));
	if (*out == NULL)
		return (0);
	(*out)[out_size] = '\0';
	out_pos = 0;
	i = 0;
	while (*in)
	{
		while ((*in)[i])
			(*out)[out_pos++] = (*in)[i++];
		if ((*in)[i + 1] == '*')
		{
			(*out)[out_pos++] = '\0';
			i += 2;
			continue ;
		}
		i = 0;
		in++;
	}
	while (last[i])
		(*out)[out_pos++] = last[i++];
	return (out_pos);
}
