/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:26:12 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:47:33 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inner_loop(const char *str, const char *to_find,
		size_t remaining_len)
{
	size_t	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (i >= remaining_len || str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief finds the first occurence of substring in a string and returns a
 * pointer to it or NULL.
 * This function returns the first occurence of a complete substring in it
 * if there is such an occurence. If there is not, it returns null.
 * It only searches up to (size_t) len chars.
 *
 * @param str (const char *) string (haystack)
 * @param to_find (const char *) string to find (needle)
 * @param len (size_t) length to search
 * @return (const char *) pointer to the location of needle or null
 */
const char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	size_t	iter;

	iter = 0;
	if (*to_find == '\0')
	{
		return (&str[iter]);
	}
	while (str[iter] && iter < len)
	{
		if (str[iter] == *to_find)
		{
			i = inner_loop(&str[iter], to_find, len - iter);
			if (i == 1)
			{
				return (&str[iter]);
			}
		}
		iter++;
	}
	return (NULL);
}
