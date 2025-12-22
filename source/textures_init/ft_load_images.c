/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 18:56:48 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-15 18:56:48 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Tries to load all inputed textures into images and store them
 * in data. On error, it returns false
 */
bool ft_load_images(t_data *data)
{
	data->image_map_floor = mlx_xpm_file_to_image(data->mlx, MINIMAP_FLOOR, &data->texture_width, &data->texture_heigth);
	if (!data->image_map_floor)
		return (false);
	data->image_map_wall = mlx_xpm_file_to_image(data->mlx, MINIMAP_WALL, &data->texture_width, &data->texture_heigth);
	if (!data->image_map_wall)
		return (false);
	data->image_map_player = mlx_xpm_file_to_image(data->mlx, MINIMAP_ARROW, &data->arr_width, &data->arr_width);
	if (!data->image_map_player)
		return (false);
	data->image_no = mlx_xpm_file_to_image(data->mlx, data->path_no, &data->texture_width, &data->texture_heigth);
	if (!data->image_no)
		return (false);
	data->image_so = mlx_xpm_file_to_image(data->mlx, data->path_so, &data->texture_width, &data->texture_heigth);
	if (!data->image_so)
		return (false);
	data->image_ea = mlx_xpm_file_to_image(data->mlx, data->path_ea, &data->texture_width, &data->texture_heigth);
	if (!data->image_ea)
		return (false);
	data->image_we = mlx_xpm_file_to_image(data->mlx, data->path_we, &data->texture_width, &data->texture_heigth);
	if (!data->image_we)
		return (false);
	return (ft_make_minimap(data));
}