/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 16:30:13 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-13 16:30:13 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_print_err(char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i])
	{
		res = write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	(void)res;
}

/**
 * Prints "Error", then error msg, returns exit code
 */
int	err_print(char *msg, int exit_code)
{
	ft_print_err("Error\n");
	ft_print_err(msg);
	ft_print_err("\n");
	return (exit_code);
}
