/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   decode.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 13:51:34 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 15:14:54 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

void	decode_str(char *target, void *source, size_t n)
{
	ft_memcpy(target, (char *)source, n);
}

void	decode_dec(char *target, void *source, size_t n)
{
	ft_sztoa_base(*(size_t *)source, "0123456789", target, n);
}

void	decode_dbl(char *target, void *source, size_t n)
{
	ft_dtoa(*(double *)source, target, n);
}

void	decode_hexl(char *target, void *source, size_t n)
{
	ft_sztoa_base(*(size_t *)source, "0123456789abcdef", target, n);
}

void	decode_hexu(char *target, void *source, size_t n)
{
	ft_sztoa_base(*(size_t *)source, "0123456789ABCDEF", target, n);
}
