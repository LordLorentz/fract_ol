/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 12:27:06 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/16 22:11:44 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

//significance of a double is 15 digits
char	*ft_dtoa(double in, char *out, int length)
{
	int			digits;
	int			past_point;

	digits = ft_sz_digits((size_t)in, 10);
	if (digits == 0)
		digits = 1;
	in = ft_dabs(in);
	past_point = 1;
	out[length--] = '\0';
	while (length-- > 0)
	{
		if (length - digits == 0)
		{
			out[length + past_point] = '.';
			past_point = 0;
		}
		out[length + past_point] =
			'0' + (unsigned int)(in * pow(10, length - digits)) % 10;
	}
	return (out);
}
