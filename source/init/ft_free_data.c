/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-11 21:43:16 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-11 21:43:16 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Reads via gnl until EOF is reached while freeing all the rest...
 * This is in order to get rid of the static buffer in gnl, else leaks
 */
void	ft_free_get_next(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

void	ft_map_space_error_exit(int fd, t_data *data, char *temp)
{
	free(temp);
	close(fd);
	ft_free_get_next(fd);
	ft_free_data(data);
	exit(err_print("Map: space between map lines", EXIT_FAILURE));
}

/**
 * Frees the char ** array of the loaded map
 */
static void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

/**
 * Freeing helper
 */
static void	ft_free_data_2(t_data *data)
{
	if (data->image_no)
		mlx_destroy_image(data->mlx, data->image_no);
	if (data->image_so)
		mlx_destroy_image(data->mlx, data->image_so);
	if (data->image_we)
		mlx_destroy_image(data->mlx, data->image_we);
	if (data->image_to_window)
		mlx_destroy_image(data->mlx, data->image_to_window);
	if (data->image_minimap)
		mlx_destroy_image(data->mlx, data->image_minimap);
	if (data->fps_string)
		free(data->fps_string);
}

/**
 * Frees everything on exist
 * used in error paths as well as normal exit paths
 */
void	ft_free_data(t_data *data)
{
	if (data->path_ea)
		free(data->path_ea);
	if (data->path_no)
		free(data->path_no);
	if (data->path_so)
		free(data->path_so);
	if (data->path_we)
		free(data->path_we);
	if (data->string_c_color)
		free(data->string_c_color);
	if (data->string_f_color)
		free(data->string_f_color);
	if (data->map)
		ft_free_map(data->map);
	if (data->image_map_floor)
		mlx_destroy_image(data->mlx, data->image_map_floor);
	if (data->image_map_player)
		mlx_destroy_image(data->mlx, data->image_map_player);
	if (data->image_map_wall)
		mlx_destroy_image(data->mlx, data->image_map_wall);
	if (data->image_ea)
		mlx_destroy_image(data->mlx, data->image_ea);
	ft_free_data_2(data);
}
