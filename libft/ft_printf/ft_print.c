/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:16:19 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/24 18:54:57 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief A wrapper function for write
 *
 * The only difference is that this function also increments i (the counter
 * variable in the ft_printf function) on every itteration, so that ft_printf
 * can return the number of printed characters.
 *
 * @param c (char to be printed)
 * @param i (unsigned int *) counter of already printed chars
 *
 * @return Does not return a value
 */
void	ft_printf_putchar(char c, unsigned int *i)
{
	write(1, &c, 1);
	(*i)++;
}

/**
 * @brief A function for printing strings (a wrapper for write with a loop)
 *
 * This function prints a string - as a basic functionality. It also mimics
 * the behaviour of the original printf in the fact that it detects a
 * possibly empty string and prints (null) in that case. Also, it increments
 * the counting variable (as a pointer) in the ft_printf function so that
 * the correct number of printed characters can be returned.
 *
 * @param s (char *) a string to be printed
 * @param i (unsigned int *) counter of printed chars in ft_printf
 *
 * @return Does not return a value
 */
void	ft_printf_putstr(char *s, unsigned int *i)
{
	int	n;

	n = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*i) += 6;
		return ;
	}
	while (s[n])
	{
		write(1, &s[n], 1);
		n++;
		(*i)++;
	}
}

/**
 * @brief A strlen function...
 *
 * @param s (char *) the string to be measured
 * @return (int) The length of the string
 */
int	ft_printf_strlen(char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}
