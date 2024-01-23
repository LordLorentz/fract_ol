/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converters_dec.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 14:40:26 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/23 13:56:14 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

char	*c_int(int *size, t_flags flags, va_list args)
{
	long	in;
	char	*out;
	t_numb	numb;
	size_t	num;

	numb.base = &decode_dec;
	numb.base_sz = 10;
	in = (long)va_arg(args, int);
	numb.sign = "";
	if (in < 0)
	{
		numb.sign = "-";
		in = -in;
	}
	num = (size_t)in;
	numb.num = &num;
	if ((flags.flags & SPACE_NOSIGN) && *numb.sign != '-')
		numb.sign = " ";
	if ((flags.flags & FORCE_SIGN) && *numb.sign != '-')
		numb.sign = "+";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_long(int *size, t_flags flags, va_list args)
{
	long	in;
	char	*out;
	t_numb	numb;
	size_t	num;

	numb.base = &decode_dec;
	numb.base_sz = 10;
	in = (long)va_arg(args, long);
	numb.sign = "";
	if (in < 0)
	{
		numb.sign = "-";
		in = -in;
	}
	num = (size_t)in;
	numb.num = &num;
	if ((flags.flags & SPACE_NOSIGN) && *numb.sign != '-')
		numb.sign = " ";
	if ((flags.flags & FORCE_SIGN) && *numb.sign != '-')
		numb.sign = "+";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_uint(int *size, t_flags flags, va_list args)
{
	size_t	in;
	char	*out;
	t_numb	numb;

	numb.base = &decode_dec;
	numb.base_sz = 10;
	in = (size_t)va_arg(args, unsigned int);
	numb.num = &in;
	numb.sign = "";
	if (flags.flags & SPACE_NOSIGN)
		numb.sign = " ";
	if (flags.flags & FORCE_SIGN)
		numb.sign = "+";
	out = fill_num(size, numb, flags);
	return (out);
}

char	*c_dbl(int *size, t_flags flags, va_list args)
{
	double	in;
	char	*out;
	t_numb	numb;

	numb.base = &decode_dbl;
	numb.base_sz = 10;
	in = (double)va_arg(args, double);
	numb.sign = "";
	if (in < 0)
	{
		numb.sign = "-";
		in = -in;
	}
	numb.num = &in;
	if ((flags.flags & SPACE_NOSIGN) && *numb.sign != '-')
		numb.sign = " ";
	if ((flags.flags & FORCE_SIGN) && *numb.sign != '-')
		numb.sign = "+";
	out = fill_num(size, numb, flags);
	return (out);
}
