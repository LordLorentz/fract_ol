/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 13:20:06 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/07 13:32:11 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	else if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(((n % 10) * (1 - 2 * (n < 0))) + '0', fd);
}
