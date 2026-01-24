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

/**
 * Coopies the specific texture row by row into the whole minimap image.
 *
 * gets addresses of src and dst (src is always the single texture), dst
 * is always the complete minimap img.
 *
 * Since all is done via mlx, bits per pixel are the same for both here.
 * then it copies 32 rows(texture heigth) from src, to dst address
 *
 * src address is i times line_len + beginning of src address
 *
 * the dst address is the beginning address + (y + i) times line_len +
 * x * bytes_pp (4). That accounts for the coordinates where I want to copy.
 *
 * Then it uses ft_memcpy to copy the data.
 */
static void	ft_copy_texture(t_t_copy *c, t_data *data, void *texture)
{
	t_make_minimap	m;

	m.src.addr = mlx_get_data_addr(texture, &m.src.bits_per_pixel,
			&m.src.line_length, &m.src.endian);
	m.dst.addr = mlx_get_data_addr(data->image_minimap, &m.dst.bits_per_pixel,
			&m.dst.line_length, &m.dst.endian);
	m.bytes_pp = m.src.bits_per_pixel / 8;
	m.i = 0;
	while (m.i < data->mini_texture_heigth)
	{
		m.src_row = m.src.addr + m.i * m.src.line_length;
		m.dst_row = m.dst.addr + (c->y + m.i) * m.dst.line_length + c->x
			* m.bytes_pp;
		ft_memcpy(m.dst_row, m.src_row, data->mini_texture_heigth * m.bytes_pp);
		m.i++;
	}
}

/**
 * Makes an image of a complete minimap from which pixels are then copied
 * to the minimap viewport.
 *
 * initializes a new image that is((map_width * texture_width) * (map_heigth *
 * texture_heigth)) big.
 *
 * Then proceeds to loop through the map(char **), checking for
 * values, and either copying the floor or wall textures at the correct
 * coordinates.
 */
bool	ft_make_minimap(t_data *data)
{
	t_t_copy	c;

	data->image_minimap = mlx_new_image(data->mlx, data->mini_texture_heigth
			* data->map_width, data->mini_texture_heigth * data->map_heigth);
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
			c.x += data->mini_texture_heigth;
			c.j++;
		}
		c.y += data->mini_texture_heigth;
		c.i++;
	}
	return (true);
}
