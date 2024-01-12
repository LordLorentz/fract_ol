/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_num.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 12:09:38 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/13 21:43:53 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

// printf("__-|ZERO_PAD: %2d, width: %2d, prsc: %2d, signsz: %d\n"
//	, flags.flags & ZERO_PAD, flags.width, flags.prsc, signsz);

static t_flags	justify_flags(t_flags flags, int digits, int signsz)
{
	if (flags.prsc < 0)
		flags.prsc = 1;
	else if (flags.flags & ZERO_PAD)
		flags.flags = flags.flags ^ ZERO_PAD;
	if (flags.flags & LEFT_JUST && flags.flags & ZERO_PAD)
		flags.flags = flags.flags ^ ZERO_PAD;
	if (flags.prsc < digits)
		flags.prsc = digits;
	flags.prsc += signsz;
	if (flags.width < flags.prsc)
		flags.width = flags.prsc;
	if (flags.flags & ZERO_PAD)
		flags.prsc = flags.width;
	return (flags);
}

char	*fill_num(int *size, t_numb n, t_flags flg)
{
	int		digits;
	int		signsz;
	char	*out;

	digits = ft_sz_digits(n.num, n.base_sz);
	signsz = ft_strlen(n.sign);
	flg = justify_flags(flg, digits, signsz);
	out = malloc(flg.prefixsz + flg.width + 2);
	if (out == NULL)
		return (NULL);
	justify_str(out + flg.prefixsz, n.num, n.base, flg);
	if (flg.flags & LEFT_JUST)
		ft_memcpy(out + flg.prefixsz, n.sign, signsz);
	else
		ft_memcpy(out + flg.prefixsz + flg.width - flg.prsc, n.sign, signsz);
	*size = flg.prefixsz + flg.width;
	return (out);
}

char	*fill_null(int *size, const char *in, t_flags flags)
{
	const int	in_size = ft_strlen(in);
	char		*out;

	if (in_size <= flags.prsc || flags.prsc < 0)
		flags.prsc = in_size;
	else
		flags.prsc = 0;
	if (flags.prsc > flags.width)
		flags.width = flags.prsc;
	out = malloc(flags.prefixsz + flags.width + 2);
	if (!out)
		return (NULL);
	justify_str(out + flags.prefixsz, (size_t)in, &out_str, flags);
	*size = flags.prefixsz + flags.width;
	return (out);
}
