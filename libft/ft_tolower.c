/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:27:49 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:49:27 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief If the provided char is uppercase, it transforms it into lowercase.
 *
 * @param param1 (int) char c
 * @return (int) lowercased char c
 */
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}
