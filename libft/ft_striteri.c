/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:35:17 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:42:28 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Iterates over a string and applies function f to all
 * characters with their index
 *
 * This function itterates over the original string it receives as an argument,
 * applies function f to each of the characters by reference passing also
 * the index of the char in the string as an argument to f.
 *
 * @param param1 (char *) source string
 * @param param2 (void (*f)(unsigned int, char *)) function f
 * @return Does not return a value
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
