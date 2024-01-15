/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:57:46 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 21:55:10 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_atod(char *in, double out)
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
			'0' + (size_t)(in * pow(10, length - digits)) % 10;
	}
	return (out);
}

// check whitespace
// negative flag
// double result = 0.0;
// result = (result * 10) + getal
// na de punt
// double div = 10
// result = result + ((getal) / div)
// div = div * 10

// int tientallen
// int sub_getallen / 100


int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	while (isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return ((int)(num * sign));
}
