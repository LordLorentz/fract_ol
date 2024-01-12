/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:27:26 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/11 15:05:02 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ltoa(long n, int *size)
{
	int		sign;
	char	*out;

	sign = 1;
	if (n < 0)
		sign = -1;
	(*size)++;
	if (n / 10 != 0)
	{
		out = ft_ltoa(n / 10, size);
		if (!out)
			return (0);
	}
	else
	{
		out = malloc(*size + 1 + (sign == -1));
		if (!out)
			return (0);
		out[*size + (sign == -1)] = '\0';
		*size = 0;
		if (sign == -1)
			*out = '-';
	}
	out[(*size)++ + (sign == -1)] = (char)((n * sign) % 10) + '0';
	return (out);
}

char	*ft_itoa(int n)
{
	int	size;

	size = 0;
	return (ft_ltoa(n, &size));
}
