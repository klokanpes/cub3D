/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_mlx_pixel_put.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 19:02:45 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-15 19:02:45 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Custom pixel put function that takes into account data alignment
 * @param img_data pointer to t_data_img
 * @param x coordinates
 * @param y coordinates
 * @param color hex ARGB value
 */
void	custom_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			* (img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/// @brief This is a line drawing algorithm inspired by Bresenhams algorithm.
/// This one could be much more effitient, but then again, it is way simpler
/// this way. - Original Bresenham only works with integers.
/// @param coords set of coordinates where from and where to draw
/// @param img_data img data for drawing into the image
/// @param color of the line to be drawn
void	ft_draw_lines(t_coords *coords, t_img_data *img_data, int color)
{
	int		dx;
	int		dy;
	int		i;
	int		step;
	float	step_x;
	float	step_y;

	dx = coords->x1 - coords->x0;
	dy = coords->y1 - coords->y0;
	step = fmax(abs(dx), abs(dy));
	if (step != 0)
	{
		step_x = (float)dx / (float)step;
		step_y = (float)dy / (float)step;
	}
	i = 0;
	while (i < step)
	{
		custom_mlx_pixel_put(img_data, (int)(coords->x0 + i * step_x),
			(int)(coords->y0 + i * step_y), color);
		i++;
	}
}