/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 17:39:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 15:28:29 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef		void (t_decode)(char *, void *, size_t);

typedef struct s_numb
{
	char		*sign;
	void		*num;
	t_decode	*base;
	size_t		base_sz;
}	t_numb;

//flag struct
typedef struct s_flags
{
	unsigned int	flags;
	int				prefixsz;
	int				width;
	int				prsc;
}	t_flags;

//internal converter functions
char		*c_mod(int *size, t_flags flags);
char		*c_chr(int *size, t_flags flags, va_list args);
char		*c_str(int *size, t_flags flags, va_list args);
char		*c_int(int *size, t_flags flags, va_list args);
char		*c_uint(int *size, t_flags flags, va_list args);
char		*c_dbl(int *size, t_flags flags, va_list args);
char		*c_hexl(int *size, t_flags flags, va_list args);
char		*c_hexu(int *size, t_flags flags, va_list args);
char		*c_addr(int *size, t_flags flags, va_list args);

//internal converter helpers
char		*fill_num(int *size, t_numb numb, t_flags flags);
char		*fill_null(int *size, const char *in, t_flags flags);

void		justify_str(char *dst, void *in, t_decode *f, t_flags flags);
t_decode	decode_str;
t_decode	decode_dec;
t_decode	decode_dbl;
t_decode	decode_hexl;
t_decode	decode_hexu;

//internal logic functions
int			count_args(const char *format);
int			find_flags(const char **format, t_flags *out, va_list args);
int			get_next_arg(const char **format, char **out, va_list args);
char		*select_converter(char type, int *size, t_flags flags, va_list args);
int			ft_arr_cat(char **in, const char *last, int out_size, char **out);

//printf functions for external use
int			ft_vsprintf(const char *format, char **out, va_list args);
int			ft_printf(const char *format, ...);
int			ft_fprintf(int fd, const char *format, ...);

#endif
