/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:44:32 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:41:05 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Prints a string to the provided file descriptor with \\n at the end.
 *
 * Prints a string to the provided file descriptor and adds a
 * new line at the end.
 *
 * @param param1 (char *) string to be printed
 * @param param2 (int) file descriptor
 * @return Does not return a value
 */
void	ft_putendl_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
