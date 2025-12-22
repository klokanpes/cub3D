/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:13:22 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 15:49:09 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Initializes memory to null.
 *
 * This function initializes memory, that it gets as an argument,
 * all to null chars. It does that up to the lenght value that is its
 * second argument.
 *
 * @param param1 void pointer to memory.
 * @param param2 size_t length of the memory.
 * @return Does not return a value.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	pointer = s;
	i = 0;
	while (i < n)
	{
		pointer[i] = '\0';
		i++;
	}
}
