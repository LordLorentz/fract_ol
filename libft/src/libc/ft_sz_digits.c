/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sz_digits.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 12:52:08 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/30 13:08:03 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sz_digits(size_t in, size_t base_size)
{
	int	out;

	out = 0;
	while (in != 0)
	{
		in = in / base_size;
		out++;
	}
	return (out);
}
