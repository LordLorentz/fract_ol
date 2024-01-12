/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:57:46 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/05 13:22:08 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

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
