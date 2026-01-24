/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_window_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 19:00:27 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-15 19:00:27 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * MLX initializer, initializes mlx, and a window.
 */
int	ft_mlx_window_innit(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_free_data(data);
		exit(err_print("mlx init error", EXIT_FAILURE));
	}
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGTH, WINDOW_NAME);
	if (!data->window)
	{
		mlx_destroy_display(data->mlx);
		ft_free_data(data);
		free(data->mlx);
		exit(err_print("mlx window error", EXIT_FAILURE));
	}
	return (0);
}
