/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 18:55:17 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-15 18:55:17 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ft_copy_texture(t_t_copy *c, t_data *data, void *texture)
{
	int i;
	int bytes_pp;
	t_img_data src;
	t_img_data dst;
	char *src_row;
	char *dst_row;
	
	src.addr = mlx_get_data_addr(texture, &src.bits_per_pixel, &src.line_length, &src.endian);
	dst.addr = mlx_get_data_addr(data->image_minimap, &dst.bits_per_pixel, &dst.line_length, &dst.endian);
	bytes_pp = src.bits_per_pixel / 8;
	i = 0;
	while(i < 32)
	{
		src_row = src.addr + i * src.line_length;
		dst_row = dst.addr + (c->y + i) * dst.line_length + c->x * bytes_pp;
		ft_memcpy(dst_row, src_row, 32 * bytes_pp);
		i++;
	}
}

bool ft_make_minimap(t_data *data)
{
	t_t_copy c;

	data->image_minimap = mlx_new_image(data->mlx, 32 * data->map_width, 32 * data->map_heigth);
	if (!data->image_minimap)
		return (false);
	c.y = 0;
	c.i = 0;
	while (data->map[c.i])
	{
		c.x = 0;
		c.j = 0;
		while (data->map[c.i][c.j])
		{
			if (data->map[c.i][c.j] == '0')
				ft_copy_texture(&c, data, data->image_map_floor);
			else
				ft_copy_texture(&c, data, data->image_map_wall);
			c.x+=32;
			c.j++;
		}
		c.y+=32;
		c.i++;
	}
	return (true);
}