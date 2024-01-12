/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 13:53:29 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/09 22:19:35 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (!out)
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}
