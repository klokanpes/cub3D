/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:34:06 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:46:10 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief iterates over a string and applies function f to all characters,
 * passing also the index of each of the characters, returns a new string
 * of changed values.
 *
 * This function itterates over the source string and applies function
 * f to all of its chars while passing as an argument also the index of
 * the char in the original string. It takes the changed chars and
 * creates a new string with them.
 *
 * @param s (const char *) source string
 * @param f (char (*f)(unsigned int, char)) function f
 * @return (char *) new string
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_array;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	new_array = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_array)
		return (NULL);
	while (s[i])
	{
		new_array[i] = f(i, s[i]);
		i++;
	}
	new_array[i] = '\0';
	return (new_array);
}
