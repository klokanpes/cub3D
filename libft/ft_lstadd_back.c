/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:33:50 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:54:38 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new node to the end of a singly linked list.
 *
 * This function traverses a linked list and inserts a new node
 * at the end of it.
 *
 * @param param1 Pointer to the head of a linked list
 * @param param2 Pointer to the new node
 * @return Does not return a value
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cursor;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		cursor = *lst;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
}
