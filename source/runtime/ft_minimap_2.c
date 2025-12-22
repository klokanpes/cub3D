/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 17:44:10 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-20 17:44:10 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_player_mini_pos	ft_get_minimap_player_pos(t_data *data)
{
	int					s;
	t_player_mini_pos	pos;

	s = MINIMAP_TILE_TEXTURE_SIZE;
	pos.x = data->player_pos_x * s;
	pos.y = data->player_pos_y * s;
	return (pos);
}

/**
 * 5 is the radius of the circle
 */
static void	ft_draw_circle_on_minimap(t_player_mini_pos pos, t_img_data to_win_data)
{
	int	dx;
	int	dy;
	int	y;
	int	x;

	y = pos.y - PLAYER_RADIUS_MINIMAP;
	while (y <= pos.y + PLAYER_RADIUS_MINIMAP)
	{
		x = pos.x - PLAYER_RADIUS_MINIMAP;
		while (x <= pos.x + PLAYER_RADIUS_MINIMAP)
		{
			dx = x - pos.x;
			dy = y - pos.y;
			if (dx * dx + dy * dy <= PLAYER_RADIUS_MINIMAP * PLAYER_RADIUS_MINIMAP)
				custom_mlx_pixel_put(&to_win_data, x, y, 0xFFFF0000);
			x++;
		}
		y++;
	}
}
/**
 * Draw a line and a circle, sets up player position and draws
 */
void	ft_put_player_on_minimap(int dst_y0, t_data *data,
		t_img_data to_win_data)
{
	t_vertex			tip;
	t_coords			a;
	double				tip_len;
	t_player_mini_pos	pos;

	pos.x = WIDTH / 2;
	pos.y = dst_y0 + 150;
	ft_draw_circle_on_minimap(pos, to_win_data);
	tip_len = 10.0;
	tip.x = (int)((double)pos.x + data->dir.dx * tip_len);
	tip.y = (int)((double)pos.y + data->dir.dy * tip_len);
	a.x0 = tip.x;
	a.y0 = tip.y;
	a.x1 = pos.x;
	a.y1 = pos.y;
	ft_draw_lines(&a, &to_win_data, 0xFF000000);
}

/**
 * prefills minimap with black pixels so that only the valid part can
 * be copied over them, the rest(out of bounds stays black)
 */
void	ft_prefill_minimap(t_minimap *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 300)
	{
		j = 0;
		while (j < 300)
		{
			custom_mlx_pixel_put(&map->to_win_data, j + map->dst_x0, i
				+ map->dst_y0, 0xFF000000);
			j++;
		}
		i++;
	}
}