/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 09:49:09 by vcerny            #+#    #+#             */
/*   Updated: 2025-03-20 09:49:09 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief returns the lenght of the provided string
 *
 * This function returns the lenght of the provided string not including
 * the null terminator byte in the result.
 *
 * @param param1 (char *) string
 * @return (int) lenght of the string
 */
int	ft_strlen_gnl(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

/**
 * @brief Initializes memory to null.
 *
 * This function initializes memory, that it gets as an argument,
 * all to null chars. It does that up to the lenght value that is its
 * second argument.
 *
 * @param param1 void pointer to memory.
 * @param param2 size_t length of the memory.
 * @return Does not return a value.
 */
void	ft_bzero_gnl(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	pointer = s;
	i = 0;
	while (i < n)
	{
		pointer[i] = '\0';
		i++;
	}
}

/**
 * @brief Copies the source string into destination buffer
 *
 * This function copies the string pointed to by src,
	into a string at the buffer pointed to by dst.
 * The caller is responsible for allocating a destination buffer large enough,
	that is, ft_strlen(src) + 1.
 *
 * @param param1 (char *) destination
 * @param param2 (const char *) source
 * @return (char *) Pointer to destination
 */
char	*ft_strcpy_gnl(char *dest, const char *src)
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

/**
 * @brief Locates character c in the string and returns the index of it.
 *
 * Returns pindex of the first occurence of the char c in the string.
 *
 * @param param1 (const char *) source string
 * @param param2 (int) character to locate
 * @return (int) index of the first occurence of c or 0
 */
int	ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (i);
	return (-1);
}

/**
 * @brief Returns a new copy of a substring specified by start and len
 *
 * This function returns new copy of a substring from within the original string
 * starting at index start of size len. If start and len are not refering to
 * a valid location, the behaviour is undefined. It uses ft_memalloc to allocate
 * space for the new substring. The substring is null terminated.
 *
 * @param param1 (char *) string
 * @param param2 (unsigned int) starting index of substring
 * @param param3 (size_t) lenght of the substring
 * @return (char *) New string containing the specified substring or NULL
 */
char	*ft_strsub_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substring;

	i = start;
	j = 0;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (j < len)
	{
		substring[j] = s[i];
		i++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}
