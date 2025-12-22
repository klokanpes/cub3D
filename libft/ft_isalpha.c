/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:27:51 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:30:19 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns 1 if a char is alphabetical
 *
 * This function takes int c as an argument, casts it as an unsigned
 * char (to avoid issues with extended ascii), then goes over its value,
 * and returns one if the char is alphabetical, and zero
 * otherwise.
 *
 * @param param1 A signle integer (with ascii value)
 * @return Returns an integer.
 */
int	ft_isalpha(int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if ((ucc < 'A' || ucc > 'Z') && (ucc < 'a' || ucc > 'z'))
		return (0);
	return (1);
}
