/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:14:36 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/24 18:54:45 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief This function is a middle step in parsing (p) pointers. It
 * differentiates between a valid adress and null and prints according to
 * the original printf.
 *
 * In case of a null pointer being passed, this function prints (nill) as
 * per classic printf behaviour, else it prints the 0x preffix and the actual
 * lowercase hexadecimal value.
 *
 * This function actually uses the variadic arguments. On each call to
 * va_arg, the next argument is accessed. The function also needs to know
 * as what type of data to cast the argument in question. For that reason
 * the arguments are accessed in here, after the function already knows,
 * what data type it is looking for.
 *
 * @param i (unsigned int *) pointer to the counter variable in
 * ft_printf. Has to be passed through the pipeline to the final
 * writing function which eventually increments it.
 * @param j (unsigned int *j) The current index in the string that
 * ft_printf is looking at right now. Needed for checking the following
 * char and parse a placeholder correctly.
 * @param args (va_list) the list of arguments used to access the
 * variadic nature of them.
 * @return Does not return a value.
 */
void	ft_printf_pointer(unsigned int *i, unsigned int *j, va_list args)
{
	void	*pointer;

	pointer = va_arg(args, void *);
	if (!pointer)
		ft_printf_putstr("(nil)", i);
	else
	{
		ft_printf_putstr("0x", i);
		ft_putnum_base((unsigned long int)pointer, "0123456789abcdef", i);
	}
	(*j) += 2;
}

/**
 * @brief This is the last parsing function in the conversion pipeline.
 *
 * This function parses (x) hexadecimal numbers in lowercase,
 * (X) hexadecimal numbers in uppercase or (%%), the actual percent
 * sign to be printed. At this point, these are the only remaining valid
 * options to be used.
 *
 * This function actually uses the variadic arguments. On each call to
 * va_arg, the next argument is accessed. The function also needs to know
 * as what type of data to cast the argument in question. For that reason
 * the arguments are accessed in here, after the function already knows,
 * what data type it is looking for.
 *
 * @param i (unsigned int *) pointer to the counter variable in
 * ft_printf. Has to be passed through the pipeline to the final
 * writing function which eventually increments it.
 * @param j (unsigned int *j) The current index in the string that
 * ft_printf is looking at right now. Needed for checking the following
 * char and parse a placeholder correctly.
 * @param s (const char *)the string that is being processed.
 * @param args (va_list) the list of arguments used to access the
 * variadic nature of them.
 * @return Does not return a value.
 */
static void	ft_converse_3(unsigned int *i, unsigned int *j, const char *s,
		va_list args)
{
	if (s[*j] == '%' && s[*j + 1] == 'x')
	{
		ft_putnum_base(va_arg(args, unsigned int), "0123456789abcdef", i);
		(*j) += 2;
	}
	else if (s[*j] == '%' && s[*j + 1] == 'X')
	{
		ft_putnum_base(va_arg(args, unsigned int), "0123456789ABCDEF", i);
		(*j) += 2;
	}
	else if (s[*j] == '%' && s[*j + 1] == '%')
	{
		ft_printf_putchar('%', i);
		(*j) += 2;
	}
}

/**
 * @brief This is the second parsing function. It parses (d)decimal values,
 * (i)integers and (u)unsigned integers. Else, if none of thouse match,
 * it passes all currently processed data to the next parsing function in
 * line.
 *
 * This function actually uses the variadic arguments. On each call to
 * va_arg, the next argument is accessed. The function also needs to know
 * as what type of data to cast the argument in question. For that reason
 * the arguments are accessed in here, after the function already knows,
 * what data type it is looking for.
 *
 * @param i (unsigned int *) pointer to the counter variable in
 * ft_printf. Has to be passed through the pipeline to the final
 * writing function which eventually increments it.
 * @param j (unsigned int *j) The current index in the string that
 * ft_printf is looking at right now. Needed for checking the following
 * char and parse a placeholder correctly.
 * @param s (const char *)the string that is being processed.
 * @param args (va_list) the list of arguments used to access the
 * variadic nature of them.
 * @return Does not return a value.
 */
static void	ft_converse_2(unsigned int *i, unsigned int *j, const char *s,
		va_list args)
{
	if (s[*j] == '%' && s[*j + 1] == 'd')
	{
		ft_printf_putnum(va_arg(args, int), i);
		(*j) += 2;
	}
	else if (s[*j] == '%' && s[*j + 1] == 'i')
	{
		ft_printf_putnum(va_arg(args, int), i);
		(*j) += 2;
	}
	else if (s[*j] == '%' && s[*j + 1] == 'u')
	{
		ft_unsigned(va_arg(args, unsigned int), i);
		(*j) += 2;
	}
	else
		ft_converse_3(i, j, s, args);
}

/**
 * @brief This is the beginning of the conversion pipeline. Through this
 * and the following functions, the placeholder is parsed as it should
 * be and is printed accordingly.
 *
 * This function parses (c) chars, (s) strings and (p) pointers. If
 * none of these match, it pases its execution to ft_converse_2.
 *
 * This function actually uses the variadic arguments. On each call to
 * va_arg, the next argument is accessed. The function also needs to know
 * as what type of data to cast the argument in question. For that reason
 * the arguments are accessed in here, after the function already knows,
 * what data type it is looking for.
 *
 * @param i (unsigned int *) pointer to the counter variable in
 * ft_printf. Has to be passed through the pipeline to the final
 * writing function which eventually increments it.
 * @param j (unsigned int *j) The current index in the string that
 * ft_printf is looking at right now. Needed for checking the following
 * char and parse a placeholder correctly.
 * @param s (const char *)the string that is being processed.
 * @param args (va_list) the list of arguments used to access the
 * variadic nature of them.
 * @return Does not return a value.
 */
void	ft_converse(unsigned int *i, unsigned int *j, const char *s,
		va_list args)
{
	if (s[*j] == '%' && s[*j + 1] == 'c')
	{
		ft_printf_putchar(va_arg(args, int), i);
		(*j) += 2;
	}
	else if (s[*j] == '%' && s[*j + 1] == 's')
	{
		ft_printf_putstr(va_arg(args, char *), i);
		(*j) += 2;
	}
	else if (s[*j] == '%' && s[*j + 1] == 'p')
	{
		ft_printf_pointer(i, j, args);
	}
	else
		ft_converse_2(i, j, s, args);
}
