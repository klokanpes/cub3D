/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:39:30 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:49:19 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a new copy of a substring specified by start and len
 *
 * This function returns new copy of a substring from within the original
 * string starting at index start of size len. If start and len are not
 * refering to a valid location, the behaviour is undefined. It uses malloc to
 * allocate space for the new substring. The substring is null terminated.
 *
 * @param s (char *) string
 * @param start (unsigned int) starting index of substring
 * @param len (size_t) lenght of the substring
 * @return (char *) New string containing the specified substring or NULL
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	i = 0;
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
