/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:40:34 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:55:06 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count the nodes in a singly-linked list.
 * @param lst Pointer to the first node (NULL for empty list).
 * @return Number of nodes.
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*cursor;
	int		counter;

	counter = 0;
	cursor = lst;
	while (cursor)
	{
		counter++;
		cursor = cursor->next;
	}
	return (counter);
}
