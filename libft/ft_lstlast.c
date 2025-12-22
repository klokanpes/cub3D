/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:46:24 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:54:56 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  Return the last node of a singly-linked list.
 *
 * Advances through the list until it finds the node whose `next` is NULL.
 *
 * @param  lst  Pointer to the first node of the list (NULL for an empty list).
 * @return Pointer to the last node, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cursor;

	if (!lst)
		return (NULL);
	cursor = lst;
	while (cursor->next)
		cursor = cursor->next;
	return (cursor);
}
