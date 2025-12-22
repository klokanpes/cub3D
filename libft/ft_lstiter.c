/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:42:24 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:54:53 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Itterates over the list applying the f function to all elements
 *
 * This function itterates over the lenght of the list and applies the f function
 * to the content of all nodes within the list.
 *
 * @param lst (t_list *)Pointer to the head (or location in) of the linked list
 * @param f (void (*f)(void *))Pointer to the f function
 * @return Does not return a value
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cursor;

	if (!lst || !f)
		return ;
	cursor = lst;
	while (cursor)
	{
		f(cursor->content);
		cursor = cursor->next;
	}
}
