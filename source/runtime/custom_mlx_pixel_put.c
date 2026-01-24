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
 * Custom pixel put function that takes into account data alignment
 *
 * Was mentioned in multiple docs, since the builtin is supposedly not mem
 * aligned so this should be faster. It computes the dst address and puts
 * the color value there (like a pixel)
 */
void	custom_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			* (img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * This is a line drawing algorithm inspired by Bresenhams algorithm.
 * This one could be much more effitient, but then again, it is way simpler
 * this way. - Original Bresenham only works with integers.
 *
 * What it does is goes pixel by pixel in a "line" while deciding which
 * of the two pixels in the "line" is more in "line"...
 *
 * Imagine a line being drawn in a matrix. It can't, since it would go
 * through multiple points. So this algorithm decides where to draw the
 * line based on which point is more in "line".
 *
 * It basically calculates a vector (dx, dy), then gets the max value
 * out of dx and dy.
 * If step is 0, then there is no line to be drawn...
 * Then calculates the step_x and step_y -> how many steps there should
 * be.
 * Then it proceeds to draw them, moving pixel by pixel via i, while
 * casting the whole value to an int, making an approximation basically,
 * thereby deciding where to go.
 */
void	ft_draw_lines(t_coords *coords, t_img_data *img_data, int color)
{
	t_pixel_put	p;

	p.dx = coords->x1 - coords->x0;
	p.dy = coords->y1 - coords->y0;
	p.step = fmax(abs(p.dx), abs(p.dy));
	if (p.step != 0)
	{
		p.step_x = (float)p.dx / (float)p.step;
		p.step_y = (float)p.dy / (float)p.step;
	}
	p.i = 0;
	while (p.i < p.step)
	{
		custom_mlx_pixel_put(img_data, (int)(coords->x0 + p.i * p.step_x),
			(int)(coords->y0 + p.i * p.step_y), color);
		p.i++;
	}
}
