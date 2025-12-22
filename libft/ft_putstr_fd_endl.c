/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_endl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 14:52:08 by vcerny            #+#    #+#             */
/*   Updated: 2025-08-02 14:52:08 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Prints a string to the provided file descriptor with
 * a new line at the end.
 *
 * @param param1 (const char *) string to be printed
 * @param param2 (int) file descriptor
 * @return Does not return a value
 */
void	ft_putstr_fd_endl(char const *s, int fd)
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
