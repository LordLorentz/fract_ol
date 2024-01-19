/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:57:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:10:41 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_atod(char *in)
{
	int		past_point;
	double	sign;
	double	num;

	sign = 1;
	if (*in == '-' && ++in)
		sign = -1;
	past_point = 0;
	num = 0;
	while (*in >= '0' && *in <= '9')
	{
		if (past_point == 0)
			num *= 10;
		num += (double)(*in - '0') *pow(10, -past_point);
		in++;
		if (*in == '.' || past_point != 0)
		{
			if (past_point == 0)
				in++;
			past_point++;
		}
	}
	return (num * sign);
}
