/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:32:42 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 16:31:41 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_save_num_string(int len, int n, char *string)
{
	if (n < 0)
	{
		string[0] = '-';
		n *= -1;
	}
	if (n < 10)
		string[len - 1] = n + '0';
	else
	{
		ft_save_num_string(len - 1, n / 10, string);
		string[len - 1] = (n % 10) + '0';
	}
}

/**
 * @brief Transorms an integer into a string of chars.
 *
 * This function takes int c as an argument, and transforms
 * it into a string of corresponding characters. It takes care
 * of edge cases(INT_MIN && INT_MAX). The main logic is very
 * similar to ft_putnumber. The operation is recursive as
 * well, but inserts into a string instead of printing.
 *
 * @param param1 Signle integer
 * @return String of characters or NULL
 */
char	*ft_itoa(int n)
{
	char	*string;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	len = ft_count_digits(n);
	if (n < 0)
		len++;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	ft_save_num_string(len, n, string);
	string[len] = '\0';
	return (string);
}
