/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 18:58:07 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-15 18:58:07 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Used for MLX errors, prints error, frees data, exits(1)
 */
int	ft_err_terminate(t_data *data, char *err_msg)
{
	ft_free_data(data);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	printf("Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
	return (0);
}

/**
 * Used en ESC press, terminates MLX, frees data, exits
 */
int	ft_terminate(t_data *data)
{
	ft_free_data(data);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	printf("Thanks for playing. Goodbye!\n");
	exit(EXIT_SUCCESS);
	return (0);
}