/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:43:02 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:55:00 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_2(t_list **lst, t_list **new_head, t_list **new_tail,
		t_list **node)
{
	if (!(*new_head))
		*new_head = *node;
	else
		(*new_tail)->next = *node;
	*new_tail = *node;
	*lst = (*lst)->next;
}

/**
 * @brief Iterate over a list, applying `f` to each node’s
 * content to build a new list.
 *
 * Creates a new list by applying the function `f` to the content of each node
 * in the input list `lst`. For each element, `f` should return a pointer to
 * a newly‐allocated content. If allocation fails at any point, `del` is used
 * to free all content in the new list before returning NULL.
 *
 * @param lst Pointer to the first node of the source list (or NULL).
 * @param f Function to apply: takes the old content pointer, returns
 * a newly-allocated content pointer (or NULL on error).
 * @param del Function to free a content pointer.
 * @return  Pointer to the first node of the new list, or NULL if
 * allocation failed.  The caller is responsible for clearing
 * the new list with `ft_lstclear(&new_list, del)`.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_list_tail;
	t_list	*node;
	void	*new_content;

	new_list_head = NULL;
	new_list_tail = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list_head, del);
			return (NULL);
		}
		node = ft_lstnew(new_content);
		if (!node)
		{
			del(new_content);
			ft_lstclear(&new_list_head, del);
			return (NULL);
		}
		ft_lstmap_2(&lst, &new_list_head, &new_list_tail, &node);
	}
	return (new_list_head);
}
