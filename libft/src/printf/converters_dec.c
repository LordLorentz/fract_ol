/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converters_num.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 14:40:26 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/09 21:40:32 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

char	*c_int(int *size, t_flags flags, va_list args)
{
	long	in;
	char	*out;
	t_numb	numb;

	numb.base = &out_dec;
	numb.base_sz = 10;
	in = (long)va_arg(args, int);
	numb.sign = "";
	if (in < 0)
	{
		numb.sign = "-";
		in = -in;
	}
	numb.num = (size_t)in;
	if ((flags.flags & SPACE_NOSIGN) && *numb.sign != '-')
		numb.sign = " ";
	if ((flags.flags & FORCE_SIGN) && *numb.sign != '-')
		numb.sign = "+";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_uint(int *size, t_flags flags, va_list args)
{
	char	*out;
	t_numb	numb;

	numb.base = &out_dec;
	numb.base_sz = 10;
	numb.num = (size_t)va_arg(args, unsigned int);
	numb.sign = "";
	if (flags.flags & SPACE_NOSIGN)
		numb.sign = " ";
	if (flags.flags & FORCE_SIGN)
		numb.sign = "+";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_hexl(int *size, t_flags flags, va_list args)
{
	char	*out;
	t_numb	numb;

	numb.base = &out_hexl;
	numb.base_sz = 16;
	numb.num = (size_t)va_arg(args, unsigned int);
	numb.sign = "";
	if (flags.flags & HEX_PREFIX && numb.num)
		numb.sign = "0x";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_hexu(int *size, t_flags flags, va_list args)
{
	char	*out;
	t_numb	numb;

	numb.base = &out_hexu;
	numb.base_sz = 16;
	numb.num = (size_t)va_arg(args, unsigned int);
	numb.sign = "";
	if (flags.flags & HEX_PREFIX && numb.num)
		numb.sign = "0X";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_addr(int *size, t_flags flags, va_list args)
{
	char	*out;
	t_numb	numb;

	numb.base = &out_hexl;
	numb.base_sz = 16;
	numb.num = (size_t)va_arg(args, void *);
	numb.sign = "0x";
	if (numb.num != 0)
		out = fill_num(size, numb, flags);
	else
		out = fill_null(size, "(nil)", flags);
	return (out);
}
