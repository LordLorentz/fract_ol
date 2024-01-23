/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_arg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 12:55:48 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/23 13:56:58 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//get_next_arg increments format to after the next argument
int	get_next_arg(const char **format, char **out, va_list args)
{
	t_flags		flags;
	const char	*format_start;
	int			size;

	format_start = *format;
	flags.prefixsz = 0;
	while ((*format)[flags.prefixsz] != '%')
		flags.prefixsz++;
	*format += flags.prefixsz + 1;
	if (find_flags(format, &flags, args) == -1)
		return (-1);
	*out = select_converter(**format, &size, flags, args);
	if (*out == NULL)
		return (-1);
	*format += 1;
	while (--flags.prefixsz >= 0)
		(*out)[flags.prefixsz] = format_start[flags.prefixsz];
	return (size);
}

char	*select_converter(char type, int *size, t_flags flags, va_list args)
{
	if (type == '%')
		return (c_mod(size, flags));
	else if (type == 'c')
		return (c_chr(size, flags, args));
	else if (type == 's')
		return (c_str(size, flags, args));
	else if (type == 'd')
		return (c_int(size, flags, args));
	else if (type == 'i')
		return (c_int(size, flags, args));
	else if (type == 'l')
		return (c_long(size, flags, args));
	else if (type == 'u')
		return (c_uint(size, flags, args));
	else if (type == 'f')
		return (c_dbl(size, flags, args));
	else if (type == 'x')
		return (c_hexl(size, flags, args));
	else if (type == 'X')
		return (c_hexu(size, flags, args));
	else if (type == 'p')
		return (c_addr(size, flags, args));
	return (0);
}
