/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vsprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 12:21:58 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/13 19:48:09 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(const char *format, char **out, va_list args)
{
	char	**substrs;
	int		str_count;
	int		out_size;
	int		i;

	str_count = count_args(format);
	substrs = malloc((str_count + 1) * sizeof(size_t));
	if (substrs == NULL)
		return (-1);
	substrs[str_count] = NULL;
	i = 0;
	out_size = 0;
	while (i < str_count)
	{
		out_size += get_next_arg(&format, &substrs[i], args);
		if (substrs[i] == NULL)
			return (free_nptr_arr((void **)substrs, i), -1);
		i++;
	}
	out_size += ft_strlen(format);
	out_size = ft_arr_cat(substrs, format, out_size, out);
	free_nptr_arr((void **)substrs, str_count);
	if (*out == NULL)
		return (-1);
	return (out_size);
}
