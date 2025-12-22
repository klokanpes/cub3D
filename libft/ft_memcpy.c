/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:47:09 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:38:11 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies memory from src to dest until n is reached
 *
 * This function copies memory from source to destination until the
 * size n is reached. Then it returns a pointer to the destination memory.
 * All of this is done with casting the contents of the src memory as
 * unsigned char *.
 *
 * @param dest (void *) pointer to the destination memory
 * @param src (const void *) pointer to the source memory
 * @param n (size_t) value how much to copy
 * @return (void *) pointer to the beginning of dest memory
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		*destination;

	i = 0;
	source = (const unsigned char *)src;
	destination = dest;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
