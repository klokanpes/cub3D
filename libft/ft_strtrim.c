/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:43:32 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:48:41 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (0);
		i++;
	}
	return (1);
}

static size_t	ft_beginning(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_charcmp(s[i], set))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_end(const char *s, const char *set)
{
	size_t	i;

	if (s[0] == '\0')
		return (0);
	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (ft_charcmp(s[i], set))
			return (i);
		i--;
	}
	return (i);
}

/**
 * @brief Allocates memory (using malloc) and returns a
 * copy of ’s’ with characters from ’set’ removed
 * from the beginning and the end.
 *
 * @param s (const char *) string to remove from
 * @param set (const char *) characters to be removed
 * @return (char *) new copy of the provided string or NULL
 */
char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new_string;

	start = ft_beginning(s, set);
	end = ft_end(s, set);
	if (start > end || !s[0])
		return (ft_strdup(""));
	new_string = (char *)malloc((((end - start) + 1) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < (end - start) + 1)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
