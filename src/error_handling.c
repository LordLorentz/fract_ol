/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 13:56:22 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/17 14:33:10 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_exit(int state, const char *function, int line)
{
	ft_printf("Exiting with state %d in function %s at line %d\n",
		state, function, line);
	exit(state);
}
