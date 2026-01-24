/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-23 23:35:51 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-23 23:35:51 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Guards agains the ray_dir being 0 because of division by 0. if it is, it
 * gives it a bigger value, else it returns the absolute value of 1 over
 * ray_dir
 */
double	ft_get_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	return (fabs(1 / ray_dir));
}

/**
 * Gets the color of a specific pixel
 * Gets the t_img_data as argument, takes the address from it, computes the
 * byte offset since the beginning of the address via x, y, the length of
 * the line (of pixels including padding) and bits per pixel
 * then it just gets the correct address including the offset, byte_offset
 * is divided by 4 because bits_pp is 32 in mlx.
 * Then it just returns the dereferenced value from there, which is the color
 * of the particular pixel at these coordinates
 */
uint32_t	ft_get_pixel_color(t_img_data *img, int x, int y, t_data *data)
{
	int			byte_offset;
	uint32_t	*pixel_ptr;

	if (img->bits_per_pixel / 8 == 4)
	{
		byte_offset = y * img->line_length + x * (img->bits_per_pixel / 8);
		pixel_ptr = (uint32_t *)img->addr + byte_offset / 4;
		return (*pixel_ptr);
	}
	else
	{
		ft_free_data(data);
		exit(err_print("Image format error", EXIT_FAILURE));
	}
}

/**
 * initial values for the raycaster. Sets up the offsets for drawing on the
 * screen and the images of the textures (only pointers are loaded here)
 */
void	ft_raycast_initial_data(t_data *data, t_raycast *r_data)
{
	r_data->x_offset = WIDTH / 2 - VIEWPORT_WIDTH / 2;
	r_data->y_offset = 50;
	r_data->idata.addr = mlx_get_data_addr(data->image_to_window,
			&r_data->idata.bits_per_pixel, &r_data->idata.line_length,
			&r_data->idata.endian);
	r_data->north.addr = mlx_get_data_addr(data->image_no,
			&r_data->north.bits_per_pixel, &r_data->north.line_length,
			&r_data->north.endian);
	r_data->south.addr = mlx_get_data_addr(data->image_so,
			&r_data->south.bits_per_pixel, &r_data->south.line_length,
			&r_data->south.endian);
	r_data->east.addr = mlx_get_data_addr(data->image_ea,
			&r_data->east.bits_per_pixel, &r_data->east.line_length,
			&r_data->east.endian);
	r_data->west.addr = mlx_get_data_addr(data->image_we,
			&r_data->west.bits_per_pixel, &r_data->west.line_length,
			&r_data->west.endian);
}

void	ft_raycast_set_vals_in_loop(t_data *data, t_raycast *r_data, int i)
{
	r_data->camera_x = 2 * i / (double)VIEWPORT_WIDTH - 1;
	r_data->ray_dir_x = data->dir.dx + data->plane.dx * r_data->camera_x;
	r_data->ray_dir_y = data->dir.dy + data->plane.dy * r_data->camera_x;
	r_data->map_x = (int)data->player_pos_x;
	r_data->map_y = (int)data->player_pos_y;
	r_data->delta_dist_x = ft_get_delta_dist(r_data->ray_dir_x);
	r_data->delta_dist_y = ft_get_delta_dist(r_data->ray_dir_y);
	r_data->hit = 0;
}

void	ft_raycast_set_step_x_n_y(t_data *data, t_raycast *r_data)
{
	if (r_data->ray_dir_x < 0)
	{
		r_data->step_x = -1;
		r_data->side_dist_x = (data->player_pos_x - r_data->map_x)
			* r_data->delta_dist_x;
	}
	else
	{
		r_data->step_x = 1;
		r_data->side_dist_x = (r_data->map_x + 1.0 - data->player_pos_x)
			* r_data->delta_dist_x;
	}
	if (r_data->ray_dir_y < 0)
	{
		r_data->step_y = -1;
		r_data->side_dist_y = (data->player_pos_y - r_data->map_y)
			* r_data->delta_dist_y;
	}
	else
	{
		r_data->step_y = 1;
		r_data->side_dist_y = (r_data->map_y + 1.0 - data->player_pos_y)
			* r_data->delta_dist_y;
	}
}
