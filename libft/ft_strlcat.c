/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:52:00 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:44:51 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_dest_len(char *dest, size_t size)
{
	size_t	dlen;

	dlen = 0;
	if (size == 0)
		return (dlen);
	while (dlen < size && dest[dlen])
		dlen++;
	return (dlen);
}

/**
 * @brief concatonates two strings into the destination buffer
 *
 * This function concatonates two strings together into the destination
 * buffer while being careful about whether there is enough space for
 * the entire operation. If not enough size is provided via (size_t)
 * size or if there is efectively not enough space in the destination
 * for any operation, it does nothing an only returns the ammount of
 * space that would be needed for the operation.
 *
 * If there is space to copy only a part of src to dest it does so, but
 * returns the complete size required for the complete operation so that
 * it can be checked against ft_strlen(dest) to see, whether enough
 * space was made available.
 *
 * In the end, this function returns a (size_t) value necessary for the
 * complete copy of src to dest, which can again be compared with
 * ft_strlen(src).
 *
 * NULL termination of the dest string is not guaranteed if
 * there is not enough space.
 *
 * @param dest (char *) destination string
 * @param src (const char *) source string
 * @param size (size_t) available size for copying
 * @return (size_t) space required for complete copy of src into dest
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dest_len = calculate_dest_len(dest, size);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (dest_len >= size)
		return (src_len + size);
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	if (dest_len < size)
		dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}
