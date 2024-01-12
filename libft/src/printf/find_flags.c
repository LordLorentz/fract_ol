/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_flags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 12:57:53 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/13 21:49:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

//*(*format)++
//norminette made me do it.
static int	set_bitflags(const char **format, t_flags *out)
{
	while (**format == '-' || **format == '+' || **format == ' '
		|| **format == '#' || **format == '0')
	{
		if (**format == '-')
			out->flags |= LEFT_JUST;
		if (**format == '+')
			out->flags |= FORCE_SIGN;
		if (**format == ' ')
			out->flags |= SPACE_NOSIGN;
		if (**format == '#')
			out->flags |= HEX_PREFIX;
		if (**format == '0')
			out->flags |= ZERO_PAD;
		(*format)++;
	}
	return (0);
}

static void	get_va_flag(const char **format, int *out, va_list args)
{
	if (ft_isdigit(**format))
		*out = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '*')
	{
		*out = va_arg(args, int) + 0;
		(*format)++;
	}
}

//increments format to the end of the flags, pointing at the type specifier
int	find_flags(const char **format, t_flags *out, va_list args)
{
	out->flags = 0;
	if (set_bitflags(format, out) == -1)
		return (-1);
	out->width = 0;
	get_va_flag(format, &out->width, args);
	if (out->width < 0)
	{
		out->flags |= LEFT_JUST;
		out->width *= -1;
	}
	out->prsc = -1;
	if (**format == '.')
	{
		(*format)++;
		out->prsc = 0;
		get_va_flag(format, &out->prsc, args);
	}
	return (0);
}
