/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:30:32 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:30:45 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns char value if a char is numerical
 *
 * This function takes int c as an argument, casts it as an unsigned
 * char (to avoid issues with extended ascii), then goes over its value,
 * and returns positive value if the char is numerical, and zero
 * otherwise.
 *
 * @param param1 A signle integer (with ascii value)
 * @return Returns an integer.
 */
int	ft_isdigit(int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if (ucc < '0' || ucc > '9')
		return (0);
	return (1);
}
