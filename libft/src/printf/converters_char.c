/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converters_char.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 14:40:26 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/13 20:58:11 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

char	*c_mod(int *size, t_flags flags)
{
	char	*out;

	out = malloc(flags.prefixsz + 1 + 2);
	out[flags.prefixsz] = '%';
	out[flags.prefixsz + 1] = '\0';
	out[flags.prefixsz + 2] = '\0';
	*size = flags.prefixsz + 1;
	return (out);
}

//sets 1 byte past the null terminator to a flag that is true when
//the null should be taken into account in the total written characters.
char	*c_chr(int *size, t_flags flags, va_list args)
{
	char	*out;
	char	c;
	int		c_offset;

	c = (unsigned char)va_arg(args, int);
	if (flags.width < 1)
		flags.width = 1;
	out = malloc(flags.prefixsz + flags.width + !c + 2);
	ft_memset(out + flags.prefixsz, ' ', flags.width + !c);
	if (flags.flags & LEFT_JUST)
		c_offset = flags.prefixsz;
	else
		c_offset = flags.prefixsz + flags.width - 1;
	out[c_offset] = c;
	if (!c)
		out[c_offset + 1] = '*';
	out[flags.prefixsz + flags.width + !c] = '\0';
	out[flags.prefixsz + flags.width + !c + 1] = '\0';
	*size = flags.prefixsz + flags.width;
	return (out);
}

//Unecessary complexity is an original sin.
//Struct recycling isn't nearly as bad in comparison
char	*c_str(int *size, t_flags flags, va_list args)
{
	char	*out;
	char	*in;
	int		in_size;

	in = va_arg(args, char *);
	if (in == NULL)
		return (fill_null(size, "(null)", flags));
	in_size = 0;
	while (in[in_size] != '\0' && (in_size < flags.prsc || flags.prsc < 0))
		in_size++;
	if (in_size < flags.prsc || flags.prsc < 0)
		flags.prsc = in_size;
	if (flags.prsc > flags.width)
		flags.width = flags.prsc;
	out = malloc(flags.prefixsz + flags.width + 2);
	if (!out)
		return (NULL);
	justify_str(out + flags.prefixsz, (size_t)in, &out_str, flags);
	*size = flags.prefixsz + flags.width;
	return (out);
}
