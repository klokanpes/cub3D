/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:35:46 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:30:57 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns 1 if a char is printable ASCII value.
 *
 * This function takes int c as an argument, casts it as an unsigned
 * char (to avoid issues with extended ascii), then goes over its value,
 * and returns a positive value if the char is within the ASCII
 * printable value range, and zero otherwise.
 *
 * @param param1 A signle integer (with ascii value)
 * @return Returns an integer.
 */
int	ft_isprint(int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if (ucc < 32 || ucc > 126)
		return (0);
	return (1);
}
