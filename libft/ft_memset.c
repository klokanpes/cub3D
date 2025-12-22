/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:48:22 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:40:28 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Initializes memory to a provided value
 *
 * Goes over the provided memory location up to n size, casts the memory
 * as unsgigned char * as well as the c value is cast as unsigned char.
 * It then intializes the memory to the value in char. lastly, it returns
 * the pointer to the beginning of the initialized memory.
 * Basically it is a hard delete of data.
 *
 * @param s (void *) pointer to the memory
 * @param c (int) int value to be assigned to the memory
 * @param n (size_t) value how much to initialize
 * @return (void *) pointer to the memory
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = s;
	while (i < n)
	{
		pointer[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
