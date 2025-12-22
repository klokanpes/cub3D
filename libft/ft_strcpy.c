/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-09 16:23:13 by vcerny            #+#    #+#             */
/*   Updated: 2025-03-09 16:23:13 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Copies the source string into destination buffer
 *
 * This function copies the string pointed to by src,
 * into a string at the buffer pointed to by dst.
 * The caller is responsible for allocating a destination 
 * buffer large enough,that is, ft_strlen(src) + 1.
 *
 * @param param1 (char *) destination
 * @param param2 (const char *) source
 * @return (char *) Pointer to destination
 */
char	*ft_strcpy(char *dest, const char *src)
{
	char	*pointer;

	pointer = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (pointer);
}
