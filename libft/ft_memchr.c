/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:44:20 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:36:26 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the location of c in the provided memory
 *
 * Searches for the value of c,
 * cast as an unsigned char within the provided memory
 * up to size n. If c is found, it returns its location,
 * else it returns NULL.
 *
 * @param param1 (const void *) pointer to the source memory)
 * @param param2 (int) value to look for
 * @param param3 (size_t) value how much to search
 * @return (void *) pointer to the dest memory to the location of c or NULL
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*source;

	source = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return ((void *)&source[i]);
		i++;
	}
	return (NULL);
}
