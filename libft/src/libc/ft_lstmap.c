/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 12:12:13 by mmosk         #+#    #+#                 */
/*   Updated: 2023/10/10 12:01:09 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	void	*content;

	content = (*f)(lst->content);
	if (!content)
		return (0);
	out = ft_lstnew(content);
	if (!out)
	{
		(*del)(content);
		return (0);
	}
	if (!lst->next)
		return (out);
	out->next = ft_lstmap(lst->next, f, del);
	if (!out->next)
	{
		ft_lstdelone(out, del);
		return (0);
	}
	return (out);
}
