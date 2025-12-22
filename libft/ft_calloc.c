/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:36:55 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 15:50:29 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_calloc() function allocates memory for an array of nmemb
 * elements of size bytes each and returns a pointer to the allocated
 * memory. The memory is set to zero. If nmemb or size is 0, then calloc()
 * returns a unique pointer value that can later be successfully
 * passed to free().
 * If the multiplication of nmemb and size would result in integer overflow,
 * then ft_calloc() returns an error.
 *
 * @param nmemb number of members
 * @param size size of each individual member
 * @return Returns a pointer to the allocated memory or NULL on error
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*memory;

	total = nmemb * size;
	if (size != 0 && total / size != nmemb)
		return (NULL);
	if (total == 0)
		total = 1;
	memory = malloc(total);
	if (!memory)
		return (NULL);
	ft_bzero(memory, total);
	return (memory);
}
