/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_nptr_arr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 21:47:09 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/24 21:49:25 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	free_nptr_arr(void **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
