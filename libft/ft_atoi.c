/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:09:35 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 15:48:36 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Takes a string and returns an int from numbers in it.
 *
 * Based on the classic atoi function. Takes const char *s as argument.
 * This function allows for one minus or plus sign at the beginning,
 * and unlimited whitespace.
 * Then it transforms numbers in the string into an integer.
 * So "   +42abc " becomes 42.
 *
 * @param param1 A string to be converted.
 * @return Returns an integer.
 */
int	ft_atoi(const char *s)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	return ((int)(num * sign));
}
