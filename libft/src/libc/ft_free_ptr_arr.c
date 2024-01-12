/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_ptr_array.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 21:47:09 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/23 21:47:37 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	free_ptr_arr(void **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
