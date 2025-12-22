/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:47:30 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:39:47 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies memory from src to dest up to n size while ensuring integrity
 *
 * This function copies memory from src to dest until size n is reached.
 * To do so, both source and destination memories are cast as unsigned char *.
 * This function also ensures that the memory is not compromised. This is done
 * through comparison of the memory locations. If destination comes after
 * source, there might be overlap. If destination comes after source but
 * destination does not come after source + n size, there is definitely
 * overlap. If there is overlap, the data is copied from last to first
 * so that the data does not get corrupted by the copying. If there is no
 * overlap, the data is copid normaly from the beginning to the end.
 *
 * @param dest (void *) pointer to the destination memory
 * @param src (const void *) pointer to the source memory)
 * @param n (size_t) value how much to copy
 * @return (void *) pointer to the dest memory
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source;

	destination = dest;
	source = (const unsigned char *)src;
	if (destination > source && destination < source + n)
	{
		i = n;
		while (i > 0)
		{
			destination[i - 1] = source[i - 1];
			i--;
		}
	}
	else
	{
		while (n--)
			*destination++ = *source++;
	}
	return (dest);
}
