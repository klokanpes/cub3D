/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-23 23:31:05 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-23 23:31:05 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Main collision algorithm, checks for colisions on all intersections
 * of the map with the current ray
 *
 * DDM loop (digital differential analysis)
 * Jumps accross map squares in either x or y directions while checking
 * whether the ray has hit a wall. If so, the whole algorithm moves forward
 * with drawing.
 */
void	ft_raycast_ddm(t_data *data, t_raycast *r_data)
{
	while (r_data->hit == 0)
	{
		if (r_data->side_dist_x < r_data->side_dist_y)
		{
			r_data->side_dist_x += r_data->delta_dist_x;
			r_data->map_x += r_data->step_x;
			r_data->side = 0;
		}
		else
		{
			r_data->side_dist_y += r_data->delta_dist_y;
			r_data->map_y += r_data->step_y;
			r_data->side = 1;
		}
		if (data->map[r_data->map_y][r_data->map_x] != '0')
			r_data->hit = 1;
	}
}

/**
 * more colision data, basically in order to compute where on the texture
 * i am in relation to where have I colided with the wall.
 */
static void	ft_raycast_colision_vals_2(t_data *data, t_raycast *r_data)
{
	if (r_data->side == 0 && r_data->ray_dir_x > 0)
		r_data->tex_x = data->texture_width - r_data->tex_x - 1;
	if (r_data->side == 1 && r_data->ray_dir_y < 0)
		r_data->tex_x = data->texture_width - r_data->tex_x - 1;
	r_data->step = (double)data->texture_heigth / (double)r_data->line_heigth;
	r_data->tex_pos = (r_data->draw_start - VIEWPORT_HEIGTH / 2
			+ r_data->line_heigth / 2) * r_data->step;
}

/**
 * This calculates specific variables to correctly draw the pixel column.
 *
 * Firstly the perp_wall_dist is the distance of the player(camera) from
 * the wall. line_height enables perspective (how far I am vs how big the
 * wall drawn should be, from that we calculate where the wall drawing should
 * start and end -> everything else will be floor and ceiling).
 *
 * Wall_x is where on the wall has the ray colided transformed to the walls
 * dimensions (texture dimensions.) via tex_x. This is important to know where
 * to take pixel data from.
 */
void	ft_raycast_colision_vals(t_data *data, t_raycast *r_data)
{
	if (r_data->side == 0)
		r_data->perp_wall_dist = (r_data->side_dist_x - r_data->delta_dist_x);
	else
		r_data->perp_wall_dist = (r_data->side_dist_y - r_data->delta_dist_y);
	r_data->line_heigth = (int)(VIEWPORT_HEIGTH / r_data->perp_wall_dist);
	r_data->draw_start = (r_data->line_heigth * -1) / 2 + VIEWPORT_HEIGTH / 2;
	if (r_data->draw_start < 0)
		r_data->draw_start = 0;
	r_data->draw_end = r_data->line_heigth / 2 + VIEWPORT_HEIGTH / 2;
	if (r_data->draw_end >= VIEWPORT_HEIGTH)
		r_data->draw_end = VIEWPORT_HEIGTH - 1;
	if (r_data->side == 0)
		r_data->wall_x = data->player_pos_y + r_data->perp_wall_dist
			* r_data->ray_dir_y;
	else
		r_data->wall_x = data->player_pos_x + r_data->perp_wall_dist
			* r_data->ray_dir_x;
	r_data->wall_x -= floor((r_data->wall_x));
	r_data->tex_x = (int)(r_data->wall_x * (double)data->texture_width);
	ft_raycast_colision_vals_2(data, r_data);
}

/**
 * Based on side and step_x/_y the texture that is being drawn is chosen.
 * This is to enable the N/S/E/W textures behaviour
 */
void	ft_raycast_set_current_texture(t_raycast *r_data)
{
	if (r_data->side == 0)
	{
		if (r_data->step_x == 1)
			r_data->tex_img = r_data->east;
		else
			r_data->tex_img = r_data->west;
	}
	else
	{
		if (r_data->step_y == 1)
			r_data->tex_img = r_data->south;
		else
			r_data->tex_img = r_data->north;
	}
}

/**
 * Draws the column of pixels in a loop. If we are above the draw_start,
 * all pixels are ceiling color. If bellow, they are all floor color.
 * Else, we get the correct pixel color value from the ft_get_pixel_color
 * and place it in the column.
 */
void	ft_raycast_draw_column(t_data *data, t_raycast *r_data, int i)
{
	int	j;

	j = 0;
	while (j < VIEWPORT_HEIGTH)
	{
		if (j < r_data->draw_start)
			custom_mlx_pixel_put(&r_data->idata, i + r_data->x_offset, j
				+ r_data->y_offset, data->ceiling_color);
		else if (j >= r_data->draw_start && j <= r_data->draw_end)
		{
			r_data->tex_y = (int)r_data->tex_pos & (data->texture_heigth - 1);
			r_data->tex_pos += r_data->step;
			r_data->color = ft_get_pixel_color(&r_data->tex_img, r_data->tex_x,
					r_data->tex_y, data);
			custom_mlx_pixel_put(&r_data->idata, i + r_data->x_offset, j
				+ r_data->y_offset, r_data->color);
		}
		else
			custom_mlx_pixel_put(&r_data->idata, i + r_data->x_offset, j
				+ r_data->y_offset, data->floor_color);
		j++;
	}
}
