/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sztoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 12:52:08 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/07 13:18:43 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sztoa_base(size_t n, char *base, char *out, int digits)
{
	size_t	base_size;

	base_size = ft_strlen(base);
	if (base_size < 2)
		return (0);
	out[digits] = '\0';
	while (digits-- != 0)
	{
		out[digits] = base[n % base_size];
		n = n / base_size;
	}
	return (out);
}
