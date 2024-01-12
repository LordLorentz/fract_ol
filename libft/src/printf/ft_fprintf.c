/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 17:39:01 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/11 13:24:04 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *format, ...)
{
	char	*out;
	int		out_size;
	va_list	args;

	va_start(args, format);
	out_size = ft_vsprintf(format, &out, args);
	va_end(args);
	if (out_size == -1)
		return (0);
	if (write(fd, out, out_size) < 0)
		return (free(out), -1);
	return (free(out), out_size);
}
