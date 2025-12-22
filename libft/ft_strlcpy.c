/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:53:10 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:45:14 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_s_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * @brief This function copies the contents of src into dst in a
 * safe way. Ensuring the resulting string is null terminated. It
 * then returns the size of the string it just tried to create.
 * On size 0, it returns immediately.
 *
 * @param dst pointer to the destination memory
 * @param src pointer to the source memory
 * @param size size_t value how many chars to copy
 *
 * @return Returns the full length of the source string.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_s_len(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
