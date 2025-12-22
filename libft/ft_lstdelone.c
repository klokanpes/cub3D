/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:35:46 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:54:49 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Deletes one node from a linked list.
 *
 * This function deletes one node of a linked list with the provided
 * del function.
 * THE CALLER IS RESPONSIBLE FOR SWITCHING THE POINTER TO THE FOLLOWING NODE!
 * This function does not switch the pointer, it only deletes the one node.
 * Therefore, if this node were in the middle of the list, the rest might get
 * orphaned.
 *
 * @param lst Pointer to the head (or location in) of the linked list
 * @param del Pointer to the del function
 * @return Does not return a value
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
