/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converters_hex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 12:19:51 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 15:32:30 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

char	*c_hexl(int *size, t_flags flags, va_list args)
{
	size_t	in;
	char	*out;
	t_numb	numb;

	numb.base = &decode_hexl;
	numb.base_sz = 16;
	in = (size_t)va_arg(args, unsigned int);
	numb.num = &in;
	numb.sign = "";
	if (flags.flags & HEX_PREFIX && in)
		numb.sign = "0x";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_hexu(int *size, t_flags flags, va_list args)
{
	size_t	in;
	char	*out;
	t_numb	numb;

	numb.base = &decode_hexu;
	numb.base_sz = 16;
	in = (size_t)va_arg(args, unsigned int);
	numb.num = &in;
	numb.sign = "";
	if (flags.flags & HEX_PREFIX && in)
		numb.sign = "0X";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_addr(int *size, t_flags flags, va_list args)
{
	size_t	in;
	char	*out;
	t_numb	numb;

	numb.base = &decode_hexl;
	numb.base_sz = 16;
	in = (size_t)va_arg(args, void *);
	numb.num = &in;
	numb.sign = "0x";
	if (in != 0)
		out = fill_num(size, numb, flags);
	else
		out = fill_null(size, "(nil)", flags);
	return (out);
}
