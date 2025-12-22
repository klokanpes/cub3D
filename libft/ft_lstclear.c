/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:38:11 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:54:46 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes the rest of a linked list from the point it gets provided
 *
 * This function traverses the linked list it gets as a parameter and
 * deletes all nodes with the provided del function while freeing allocated
 * memory. Until the end of the list.
 *
 * @param param1 Pointer to the head of the linked list
 * @param param2 Pointer to the del function
 * (that actually deletes all the data)
 * @return Does not return a value
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*cursor;

	if (!*lst || !lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		cursor = temp->next;
		del(temp->content);
		free(temp);
		temp = cursor;
	}
	*lst = NULL;
}
