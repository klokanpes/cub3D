/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 17:52:51 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-20 17:52:51 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * returns time in miliseconds
 * Has to start counting delta time again so that there is no
 * "big move" after alt+tabing back into the game
 */
int	ft_reset_time_delta(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	data->last_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (0);
}
