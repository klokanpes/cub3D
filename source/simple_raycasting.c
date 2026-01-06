/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-23 23:27:44 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-23 23:27:44 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief This just shows the whole (and simple) raycasting algorithm all
 * in one so it is easier to see what it is doing. 
 * 
 * This one is simpler in that it only paints the walls green.
 */

// void ft_raycasting(t_data *data)
// {
// 	t_img_data	idata;
// 	int			x_offset;
// 	int			y_offset;
// 	double		camera_x;
// 	double		ray_dir_x;
// 	double		ray_dir_y;
// 	int			map_x;
// 	int			map_y;
// 	double		side_dist_x;
// 	double		side_dist_y;
// 	double		delta_dist_x;
// 	double		delta_dist_y;
// 	double		perp_wall_dist;
// 	int			step_x;
// 	int			step_y;
// 	int			hit;
// 	int			side;
// 	int			line_heigth;
// 	int			draw_start;
// 	int			draw_end;
// 	int			color;

// 	x_offset = WIDTH / 2 - 1280 / 2;
// 	y_offset = 50;
// 	idata.addr = mlx_get_data_addr(data->image_to_window, &idata.bits_per_pixel,
// 			&idata.line_length, &idata.endian);
// 	for (int i = 0; i < VIEWPORT_WIDTH; i++)
// 	{
// 		camera_x = 2 * i / (double)VIEWPORT_WIDTH - 1;
// 		ray_dir_x = data->dir.dx + data->plane.dx * camera_x;
// 		ray_dir_y = data->dir.dy + data->plane.dy * camera_x;
// 		map_x = (int)data->player_pos_x;
// 		map_y = (int)data->player_pos_y;
// 		delta_dist_x = ft_get_delta_dist(ray_dir_x);
// 		delta_dist_y = ft_get_delta_dist(ray_dir_y);
// 		hit = 0;
// 		if (ray_dir_x < 0)
// 		{
// 			step_x = -1;
// 			side_dist_x = (data->player_pos_x - map_x) * delta_dist_x;
// 		}
// 		else
// 		{
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - data->player_pos_x) * delta_dist_x;
// 		}
// 		if (ray_dir_y < 0)
// 		{
// 			step_y = -1;
// 			side_dist_y = (data->player_pos_y - map_y) * delta_dist_y;
// 		}
// 		else
// 		{
// 			step_y = 1;
// 			side_dist_y = (map_y + 1.0 - data->player_pos_y) * delta_dist_y;
// 		}
// 		// DDM loop (digital differential analysis)
// 		while (hit == 0)
// 		{
// 			//jump to next map square, either in x-direction, or in y-direction
// 			if (side_dist_x < side_dist_y)
// 			{
// 			side_dist_x += delta_dist_x;
// 			map_x += step_x;
// 			side = 0;
// 			}
// 			else
// 			{
// 			side_dist_y += delta_dist_y;
// 			map_y += step_y;
// 			side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			if (data->map[map_y][map_x] != '0')
// 				hit = 1;
// 		}
// 		if(side == 0)
// 			perp_wall_dist = (side_dist_x - delta_dist_x);
// 		else
// 			perp_wall_dist = (side_dist_y - delta_dist_y);
// 		line_heigth = (int)(VIEWPORT_HEIGTH / perp_wall_dist);
// 		draw_start = (line_heigth * -1) / 2 + VIEWPORT_HEIGTH / 2;
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		draw_end = line_heigth / 2 + VIEWPORT_HEIGTH / 2;
// 		if (draw_end >= VIEWPORT_HEIGTH)
// 			draw_end = VIEWPORT_HEIGTH - 1;
// 		color = 0xFF00FF00; // green
// 		if (side == 1)
// 			color = 0xFF006400;

// 		for (int j = 0; j < VIEWPORT_HEIGTH; j++)
// 		{
// 			if (j < draw_start)
// 				custom_mlx_pixel_put(&idata, i + x_offset, j + y_offset,
// 				data->ceiling_color);
// 			else if (j >= draw_start && j <= draw_end)
// 				custom_mlx_pixel_put(&idata, i + x_offset, j
//					+ y_offset, color);
// 			else
// 				custom_mlx_pixel_put(&idata, i + x_offset, j
//					+ y_offset, data->floor_color);
// 		}
// 	}
// }