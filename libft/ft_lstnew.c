/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:28:45 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:55:03 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new list node.
 *
 * Allocates a new t_list node, sets its content pointer to the given
 * data (or NULL), and initializes next to NULL.
 *
 * @param content  Pointer to data to store in the node (shallow copy).
 * @return Pointer to the new node, or NULL on allocation failure.
 */
t_list	*ft_lstnew(void const *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (!content)
		new_node->content = NULL;
	else
		new_node->content = (void *)content;
	new_node->next = NULL;
	return (new_node);
}
