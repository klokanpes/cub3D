/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:09:07 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/24 15:40:19 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_converse(unsigned int *i, unsigned int *j, const char *s,
			va_list args);
void	ft_printf_putchar(char c, unsigned int *i);
void	ft_printf_putstr(char *s, unsigned int *i);
int		ft_printf_strlen(char *s);
void	ft_putnum_base(unsigned long int n, char *base, unsigned int *i);
void	ft_unsigned(unsigned int n, unsigned int *i);
void	ft_printf_putnum(int n, unsigned int *i);
void	ft_printf_pointer(unsigned int *i, unsigned int *j, va_list args);
int		ft_printf(const char *s, ...);

#endif
