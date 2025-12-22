/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-09 16:28:37 by vcerny            #+#    #+#             */
/*   Updated: 2025-03-09 16:28:37 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Concatonates two strings to the location of dest.
 * 
 * This function itterates over the destination string until it finds its end,
 * the copies the source after the end of the string that might have already
 * been in the destination. Lastly it null terminates the final destination 
 * string. This function does not take into account the space provided in the
 * destination. It is the responsibility of the caller to provide sufficient
 * space. If space in destination is not sufficient, the behaviour is 
 * undefined and may result in out of bounds write.
 * 
 * @param param1 (char *) destination string
 * @param param2 (const char *) source string
 * @return (char *) pointer to the destination
 */
char	*ft_strcat(char *dest, const char *src)
{
	char	*pointer;

	pointer = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (pointer);
}
