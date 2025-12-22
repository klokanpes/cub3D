/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 17:41:56 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-20 17:41:56 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

static void	ft_compute_minimap_intersection(t_minimap *map, t_data *data)
{
	map->want_x0 = map->p_pos.x - 150;
	map->want_y0 = map->p_pos.y - 150;
	map->want_h = 300;
	map->want_w = 300;
	map->want_x1 = map->want_x0 + map->want_w;
	map->want_y1 = map->want_y0 + map->want_h;
	map->src_x0 = 0;
	map->src_y0 = 0;
	map->src_x1 = data->map_width * MINIMAP_TILE_TEXTURE_SIZE;
	map->src_y1 = data->map_heigth * MINIMAP_TILE_TEXTURE_SIZE;
	map->copy_src_x0 = ft_max(map->want_x0, 0);
	map->copy_src_y0 = ft_max(map->want_y0, 0);
	map->copy_src_x1 = ft_min(map->want_x1, map->src_x1);
	map->copy_src_y1 = ft_min(map->want_y1, map->src_y1);
	map->copy_w = map->copy_src_x1 - map->copy_src_x0;
	map->copy_h = map->copy_src_y1 - map->copy_src_y0;
	map->dst_copy_x0 = map->dst_x0 + (map->copy_src_x0 - map->want_x0);
	map->dst_copy_y0 = map->dst_y0 + (map->copy_src_y0 - map->want_y0);
}

static void	ft_get_minimap_base_data(t_minimap *map, t_data *data)
{
	map->p_pos = ft_get_minimap_player_pos(data);
	map->to_win_data.addr = mlx_get_data_addr(data->image_to_window,
			&map->to_win_data.bits_per_pixel, &map->to_win_data.line_length,
			&map->to_win_data.endian);
	map->minimap_data.addr = mlx_get_data_addr(data->image_minimap,
			&map->minimap_data.bits_per_pixel, &map->minimap_data.line_length,
			&map->minimap_data.endian);
	map->bytes_pp = map->minimap_data.bits_per_pixel / 8;
	map->dy = 0;
	map->dst_x0 = WIDTH / 2 - 300 / 2;
	map->dst_y0 = 700;
}

/**
 * @todo ADD MORE COMMENTS
 * 
 * gets data about the minimap image and the image_to_window, 
 * precomputes the colision - i.e. if I want to see 300x300px
 * minimap, how does that compare to the minimap size and the
 * position of the player -> I do not want to see anything
 * out of bounds (it works and does not segfault here, but is not
 * pretty...)
 * Then prefills the minimap with black, and then copies only the
 * appropriate part of the minimap onto the viewport in image_to_window.
 */
void	ft_put_minimap_to_image(t_data *data)
{
	t_minimap	map;

	ft_get_minimap_base_data(&map, data);
	ft_prefill_minimap(&map);
	ft_compute_minimap_intersection(&map, data);
	while (map.dy < map.copy_h)
	{
		map.src_y = map.copy_src_y0 + map.dy;
		map.dst_y = map.dst_copy_y0 + map.dy;
		map.src_row_ptr = map.minimap_data.addr + map.src_y
			* map.minimap_data.line_length + map.copy_src_x0 * map.bytes_pp;
		map.dst_row_ptr = map.to_win_data.addr + map.dst_y
			* map.to_win_data.line_length + map.dst_copy_x0 * map.bytes_pp;
		ft_memcpy(map.dst_row_ptr, map.src_row_ptr, map.copy_w * map.bytes_pp);
		map.dy++;
	}
	ft_put_player_on_minimap(map.dst_y0, data, map.to_win_data);
}