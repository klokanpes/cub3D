/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:25:33 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:46:46 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to n characters
 *
 * Similar to ft_strcmp. Compares ascii values of chars in two
 * strings, but only up to n chars. Returns the difference in ascii values
 * or 0 if they are the same for up to n indices.
 *
 * @param param1 (const char *) string 1
 * @param param2 (const char *) string 2
 * @return (int) the difference in asii values of the strings or 0
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
