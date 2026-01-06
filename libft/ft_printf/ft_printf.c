/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:05:25 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/24 18:55:23 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief putnum function that prints a number according to the base of
 * said number.
 *
 * This function prints a number according to its base. It receives the base
 * to work with as an argument, gets it length and then processes all of
 * its members according to its index in the base. Other than that, it
 * works like any other putnum functions.
 *
 * @param n (unsigned long int) the number to be printed.
 * @param base (char *) a string with all members to be used for printing.
 * @param i (unsigned int *) pointer to i (counter of all chars printed)
 *
 * @return Does not return a value
 */
void	ft_putnum_base(unsigned long int n, char *base, unsigned int *i)
{
	unsigned int	base_len;

	base_len = (unsigned int)ft_printf_strlen(base);
	if (n < base_len)
		ft_printf_putchar(base[n], i);
	else
	{
		ft_putnum_base(n / base_len, base, i);
		ft_putnum_base(n % base_len, base, i);
	}
}

/**
 * @brief prints and unsigned integer.
 *
 * This function prints and unsigned integer. It is slightly
 * different that clasic putnum in the fact that it does not
 * need to cover the same base cases for error handling.
 *
 * @param n (unsigned int) to be printed
 * @param i (unsigned int *) counter of all chars that were
 * printed.
 *
 * @return Does not return a value
 */
void	ft_unsigned(unsigned int n, unsigned int *i)
{
	if (n < 10)
		ft_printf_putchar(n + '0', i);
	else
	{
		ft_unsigned(n / 10, i);
		ft_unsigned(n % 10, i);
	}
}

/**
 * @brief Standard putnum function, prints a number to the
 * standard output.
 *
 * @param n (int) the int to be processed and printed.
 * @param i (unsigned int *) pointer to i(counter of all chars
 * that were printed)
 * @return Does not return a value
 */
void	ft_printf_putnum(int n, unsigned int *i)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*i) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_printf_putchar('-', i);
		n *= -1;
	}
	if (n < 10)
		ft_printf_putchar(n + '0', i);
	else
	{
		ft_printf_putnum(n / 10, i);
		ft_printf_putnum(n % 10, i);
	}
}

/**
 * @brief This is a clone of the printf function according to the
 * mandatory part of the assignment. It takes a variable number
 * of arguments a prints a string accordingly.
 *
 * This is a clone of the printf function. It uses the va_list
 * variable, that contains all of the arguments to be used in
 * the execution of this function. This function uses va_start to
 * enable access to the arguments, the goes over the string, if
 * it sees a placeholder (beginning with %), it parses it, else
 * it just prints characters. At the end it uses va_end to end the
 * execution of the arguments.
 *
 * @param s (const char *) a string containing placeholders and
 * data to be printed.
 * @param variadic the arguments for the placeholders in the
 * function.
 *@return (int) number of characters that were printed
 */
int	ft_printf(const char *s, ...)
{
	unsigned int	i;
	unsigned int	j;
	va_list			args;

	i = 0;
	j = 0;
	va_start(args, s);
	while (s[j])
	{
		if (s[j] != '%')
		{
			ft_printf_putchar(s[j++], &i);
		}
		else
			ft_converse(&i, &j, s, args);
	}
	va_end(args);
	return (i);
}
