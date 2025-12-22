/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:23:27 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:45:25 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief returns the lenght of the provided string
 *
 * This function returns the lenght of the provided string not including
 * the null terminator byte in the result.
 *
 * @param param1 (char *) string
 * @return (int) lenght of the string
 */
int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
