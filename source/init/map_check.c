/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 20:20:23 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-13 20:20:23 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Normalizes the map, meaning that it adds empty spaces at the end of
 * each row, so that it is easier and safer to traverse it during
 * validation etc.
 */
static void	ft_normalize_map(t_data *data)
{
	int	longest_len;
	int	i;
	int	this_len;

	i = 0;
	longest_len = ft_get_longest_line_len(data->map);
	while (data->map[i])
	{
		this_len = ft_strlen(data->map[i]);
		if (this_len < longest_len)
			ft_append_spaces(data, i, longest_len - this_len);
		i++;
	}
	data->map_heigth = i;
	data->map_width = longest_len;
}

/**
 * If any neighbour is a space or the index woud go out of bounds -> false
 *
 * Checks direct neighbours as well as diagonals
 */
static bool	ft_check_neighbours(int i, int j, t_data *data)
{
	if (data->map[i][j] == '0')
	{
		if (i - 1 < 0 || j - 1 < 0 || i + 1 >= data->map_heigth || j
			+ 1 >= data->map_width)
			return (false);
		if (data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' '
			|| data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ')
			return (false);
		if (data->map[i - 1][j - 1] == ' ' || data->map[i - 1][j + 1] == ' '
			|| data->map[i + 1][j - 1] == ' ' || data->map[i + 1][j + 1] == ' ')
			return (false);
	}
	return (true);
}

/**
 * Checks whether the map is fully enclosed with '1's...
 *
 * Enforces that no '0' can be on the edge of the map and then
 * calls ft_check_neighbours.
 */
bool	ft_border_check(char **map, int width, int heigth, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && ((i == 0 || j == 0) || (i == heigth - 1
						|| j == width - 1)))
				return (false);
			if ((i > 0 && j > 0) && (i < heigth - 1 && j < width - 1))
			{
				if (!ft_check_neighbours(i, j, data))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

/**
 * Goes over the map checking all rules. If an error is found,
 * it returns false, else true
 *
 * It first checks for allowed chars, then the map gets normalized
 * so that it is easier to traverse it while checking borders...
 */
bool	ft_map_check(t_data *data)
{
	if (!ft_map_char_check(data))
		return (false);
	ft_normalize_map(data);
	if (!ft_border_check(data->map, data->map_width, data->map_heigth, data))
		return (false);
	return (true);
}
