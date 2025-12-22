/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:35:57 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:42:13 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief creates a duplicate of the string it receives as an argument
 *
 * This function creates a duplicate string of the string it receives as an
 * argument. It allocates space for it using ft_memalloc, error checks, then
 * copies the original string into the new one, null terminates it and returns
 * a pointer to the newly created string.
 *
 * @param param1 (const char *) pointer to the original string
 * @return (char *) pointer to the newly created string
 */
char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*new_string;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	i = 0;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	while (src[i] != '\0')
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
