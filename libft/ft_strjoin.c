/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:42:28 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:43:21 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief joins two strings together into a new string
 *
 * This function joins two strings tht it receives as an argument into
 * a new one, it allocates space for it using malloc. Also uses ft_strlen.
 * It then copies the two strings into the new one, null terminates it and
 * returns a pointer to the new one.
 *
 * @param s1 (const char *) string 1
 * @param s2 (const char *) string 2
 * @return (char *) pointer to the new string
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	new_string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	return (new_string);
}
