/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-16 15:35:51 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-16 15:35:51 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Checker for strings of colors
 *
 * allows for leading and trailing spaces, but no other
 * chars where colors RGB values should be
 */
static bool	ft_is_numbers(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j] && arr[i][j] == ' ')
			j++;
		if (!arr[i][j] || !ft_isdigit(arr[i][j]))
			return (false);
		while (arr[i][j] && ft_isdigit(arr[i][j]))
			j++;
		while (arr[i][j] && arr[i][j] == ' ')
			j++;
		if (arr[i][j])
			return (false);
		i++;
	}
	return (true);
}

/**
 * Frees the array made by ft_split
 */
static void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

static bool	ft_set_colors_2(t_data *data)
{
	char	**arr;
	int		red;
	int		green;
	int		blue;

	arr = ft_split(data->string_f_color, ',');
	if (!arr || !arr[0] || !arr[1] || !arr[2] || arr[3] || !ft_is_numbers(arr))
	{
		if (arr)
			ft_free_arr(arr);
		return (false);
	}
	red = ft_atoi(arr[0]);
	green = ft_atoi(arr[1]);
	blue = ft_atoi(arr[2]);
	ft_free_arr(arr);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0
			|| blue > 255))
		return (false);
	data->floor_color = (0xFF << 24) | (red << 16) | (green << 8) | blue;
	return (true);
}

/**
 * Sets colors of floor and ceiling into 32bit int with 0xAARRGGBB
 *
 * checks input for validity, then extracts the values from input and
 * bitshifts the values into position, almost identical functions for
 * the ceiling and for the floor colors
 */
bool	ft_set_colors(t_data *data)
{
	char	**arr;
	int		red;
	int		green;
	int		blue;

	if (!data->string_c_color || !data->string_f_color)
		return (false);
	arr = ft_split(data->string_c_color, ',');
	if (!arr || !arr[0] || !arr[1] || !arr[2] || arr[3] || !ft_is_numbers(arr))
	{
		if (arr)
			ft_free_arr(arr);
		return (false);
	}
	red = ft_atoi(arr[0]);
	green = ft_atoi(arr[1]);
	blue = ft_atoi(arr[2]);
	ft_free_arr(arr);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0
			|| blue > 255))
		return (false);
	data->ceiling_color = (0xFF << 24) | (red << 16) | (green << 8) | blue;
	return (ft_set_colors_2(data));
}

/**
 * Sets plane based on the player vector. It is a perpendicular
 * vector to the players direction and it enables the raycaster
 * to cast a ray for each screen pixel column. It controls the Field Of View.
 */
void	ft_set_init_plane(t_data *data)
{
	double	plane_len;

	plane_len = tan(FOV / 2);
	data->plane.dx = -data->dir.dy * plane_len;
	data->plane.dy = data->dir.dx * plane_len;
}

/**
 * Sets initial player vector based on input.
 */
bool	ft_set_initial_position(t_data *data)
{
	if (data->initial_orientation == 'X')
		return (false);
	if (data->initial_orientation == 'N')
	{
		data->dir.dx = 0.0;
		data->dir.dy = -1.0;
	}
	else if (data->initial_orientation == 'S')
	{
		data->dir.dx = 0.0;
		data->dir.dy = 1.0;
	}
	else if (data->initial_orientation == 'E')
	{
		data->dir.dx = 1.0;
		data->dir.dy = 0.0;
	}
	else if (data->initial_orientation == 'W')
	{
		data->dir.dx = -1.0;
		data->dir.dy = 0.0;
	}
	ft_set_init_plane(data);
	return (true);
}
