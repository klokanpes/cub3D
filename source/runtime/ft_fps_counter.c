/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 17:41:05 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-20 17:41:05 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Compute FPS from stored values every FRAME_COUNTER frames
 * and put it to window. There is no ghosting because I clear
 * the window on every frame
 */
void	ft_put_fps_on_screen(t_data *data, t_cub_data *c_data)
{
	char	*temp;

	data->time_d_compound += c_data->time_d;
	data->frame_counter++;
	if (data->frame_counter == FRAME_COUNTER)
	{
		if (data->time_d_compound > 0)
		{
			data->fps = (int)(1000.0 / (data->time_d_compound / data->frame_counter));
			data->time_d_compound = 0;
			data->frame_counter = 0;
			if (data->fps_string)
				free(data->fps_string);
			temp = ft_itoa(data->fps);
			if (!temp)
				ft_err_terminate(data, "Allocation failure in fps counter");
			data->fps_string = ft_strjoin("FPS: ", temp);
			if (!data->fps_string)
				ft_err_terminate(data, "Allocation failure in fps counter");
			free(temp);
		}
	}
	if (data->fps_string)
		mlx_string_put(data->mlx, data->window, WIDTH - 100, HEIGTH - (HEIGTH - 50),
			0xFFFFFFFF, data->fps_string);
}