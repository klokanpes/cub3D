/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:29:10 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 15:51:44 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns 1 if a char has ASCII value
 *
 * This function takes int c as an argument, then goes over its value,
 * and returns value of the char if it is ascii, and zero
 * otherwise.
 *
 * @param param1 A signle integer (with ascii value)
 * @return Returns an integer.
 */
int	ft_isascii(int c)
{
	unsigned char	ucc;

	ucc = c;
	if (ucc <= 127)
		return (1);
	return (0);
}
