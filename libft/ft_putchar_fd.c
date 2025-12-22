/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:36:54 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:40:43 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Prints a char to the provided file descriptor
 *
 * @param param1 (char)char to print
 * @param param2 (int)file descriptor
 * @return Does not return a value
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
