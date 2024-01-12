/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 11:58:16 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/10 12:17:25 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((*lst)->next)
		ft_lstclear((&(*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = 0;
}
