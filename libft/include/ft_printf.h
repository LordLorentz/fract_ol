/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 17:39:04 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 16:37:21 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

//macro for shrinkage purposes
# define SZ size_t

typedef struct s_numb
{
	char	*sign;
	size_t	num;
	void	(*base)(char *, SZ, SZ);
	size_t	base_sz;
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
char	*c_mod(int *size, t_flags flags);
char	*c_chr(int *size, t_flags flags, va_list args);
char	*c_str(int *size, t_flags flags, va_list args);
char	*c_int(int *size, t_flags flags, va_list args);
char	*c_uint(int *size, t_flags flags, va_list args);
char	*c_hexl(int *size, t_flags flags, va_list args);
char	*c_hexu(int *size, t_flags flags, va_list args);
char	*c_addr(int *size, t_flags flags, va_list args);

//internal converter helpers
char	*fill_num(int *size, t_numb numb, t_flags flags);
char	*fill_null(int *size, const char *in, t_flags flags);
void	justify_str(char *dst, SZ in, void (*f)(char *, SZ, SZ), t_flags flags);
void	out_str(char *target, size_t source, size_t n);
void	out_dec(char *target, size_t source, size_t n);
void	out_hexl(char *target, size_t source, size_t n);
void	out_hexu(char *target, size_t source, size_t n);

//internal logic functions
int		count_args(const char *format);
int		find_flags(const char **format, t_flags *out, va_list args);
int		get_next_arg(const char **format, char **out, va_list args);
char	*select_converter(char type, int *size, t_flags flags, va_list args);
int		ft_arr_cat(char **in, const char *last, int out_size, char **out);

//printf functions for external use
int		ft_vsprintf(const char *format, char **out, va_list args);
int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);

#endif
