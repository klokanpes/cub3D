/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:22:33 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:30:24 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns 1 if a char is alphabetical or numerical
 *
 * This function takes int c as an argument, casts it as an unsigned
 * char (to avoid issues with extended ascii), then goes over its value,
 * and returns one if the char is alphabetical or numerical, and zero
 * otherwise.
 *
 * @param param1 A signle integer (with ascii value)
 * @return Returns an integer.
 */
int	ft_isalnum(int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if ((ucc < 'A' || ucc > 'Z') && (ucc < 'a' || ucc > 'z') && (ucc < '0'
			|| ucc > '9'))
		return (0);
	return (1);
}
