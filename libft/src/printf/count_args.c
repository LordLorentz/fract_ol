/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filter_format.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 18:06:09 by mmosk         #+#    #+#                 */
/*   Updated: 2023/11/08 13:29:37 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_flags.h"

//returns the amount of substrings needed
int	count_args(const char *format)
{
	int	i;
	int	flag;
	int	amt;

	i = 0;
	flag = 0;
	amt = 0;
	while (format[i])
	{
		if (flag == 0 && format[i] == '%')
		{
			amt++;
			flag = 1;
		}
		else if (flag == 1 && format[i] == '%')
		{
			flag = 0;
		}
		else
		{
			flag = 0;
		}
		i++;
	}
	return (amt);
}
