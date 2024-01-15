/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 14:49:08 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 14:51:52 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_dabs(double in)
{
	if (in < 0)
		return (-in);
	return (in);
}

long	ft_labs(long in)
{
	if (in < 0)
		return (-in);
	return (in);
}
