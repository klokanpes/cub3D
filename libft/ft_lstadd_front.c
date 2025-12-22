/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:38:35 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:54:42 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds new node to the beginning of a linked list.
 *
 * This function adds a new node to the beginning of a singly linked
 * list.
 *
 * @param lst Pointer to the head of the linked list
 * @param new Pointer to the new node
 * @return Does not return a value
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
