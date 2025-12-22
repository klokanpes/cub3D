/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:45:54 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:37:19 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two memory locations and returns their difference
 *
 * Compares memories in s1 and s2 that are both cast as unsigned char *.
 * In essence, it is very similar to strncmp. It compares memory until
 * n is reached or until there is difference in the memory.
 *
 * @param s1 (const void *) pointer to s1 memory
 * @param s2 (const void *) pointer to s2 memory
 * @param n (size_t) value how much to compare
 * @return (int) value of the difference
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*source1;
	const unsigned char	*source2;

	i = 0;
	source1 = (const unsigned char *)s1;
	source2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (source1[i] != source2[i])
			return (source1[i] - source2[i]);
		i++;
	}
	return (0);
}
