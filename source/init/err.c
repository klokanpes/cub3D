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

/**
 * Prints "Error", then error msg, returns exit code
 */
int	err_print(char *msg, int exit_code)
{
	printf("Error\n%s\n", msg);
	return (exit_code);
}