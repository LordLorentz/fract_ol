/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   justify_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 13:51:34 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/08 14:21:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

void	out_str(char *target, size_t source, size_t n)
{
	ft_memcpy(target, (char *)source, n);
}

void	out_dec(char *target, size_t source, size_t n)
{
	ft_sztoa_base(source, "0123456789", target, n);
}

void	out_hexl(char *target, size_t source, size_t n)
{
	ft_sztoa_base(source, "0123456789abcdef", target, n);
}

void	out_hexu(char *target, size_t source, size_t n)
{
	ft_sztoa_base(source, "0123456789ABCDEF", target, n);
}

void	justify_str(char *dst, SZ in, void (*f)(char *, SZ, SZ), t_flags flags)
{
	dst[flags.width] = '\0';
	dst[flags.width + 1] = '\0';
	if (flags.flags & LEFT_JUST)
	{
		(*f)(dst, in, flags.prsc);
		ft_memset(dst + flags.prsc, ' ', flags.width - flags.prsc);
	}
	else
	{
		(*f)(dst + (flags.width - flags.prsc), in, flags.prsc);
		ft_memset(dst, ' ', flags.width - flags.prsc);
	}
}
