/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:27:16 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:47:48 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a pointer to the last occurrence of the character c in the
 * string s.
 *
 * This function itterates over the s string, while storing the pointer to each
 * occurence of c it finds along the way. In the end, it returns the last one.
 * If none was found, it returns NULL.
 *
 * @param param1 (const char *) string
 * @param param2 (int) char c to find
 * @return (const char *) pointer to the last location of c or null
 */
const char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*result_pointer;

	result_pointer = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			result_pointer = &s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s[i]);
	return (result_pointer);
}
