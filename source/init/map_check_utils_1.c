/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 17:21:45 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-13 17:21:45 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * sets the initial player position, orientation and clears the place in the
 * map to be normal empty space 
 */
static void ft_set_initial_player_coords(t_data *data, int i, int j)
{
	data->initial_orientation = data->map[i][j];
	data->map[i][j] = '0';
	data->player_pos_x = (float)j + 0.5;
	data->player_pos_y = (float)i + 0.5;
}

/**
 * Goes over the map, checks that it only contains allowed chars,
 * and counts how many player initial positions there are. If there
 * are more then 1, it returns false, else returns true.
 * 
 * Also, facilitates the setting of the initial player position
 * being stored in data
 */
bool ft_map_char_check(t_data *data)
{
	int i;
	int j;
	int player_pos_counter;

	i = 0;
	player_pos_counter = 0;
	while (data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", (int)data->map[i][j]))
				return(false);
			if (ft_strchr("NSEW", (int)data->map[i][j]))
			{
				ft_set_initial_player_coords(data, i, j);
				player_pos_counter++;
			}
			j++;
		}
		i++;
	}
	if (player_pos_counter == 1)
		return (true);
	return (false);
}

/**
 * Returns the length of the longest line in the map
 */
int ft_get_longest_line_len(char **map)
{
	int i;
	int longest_len;
	int this_len;

	i = 0;
	longest_len = 0;
	while (map[i])
	{
		this_len = ft_strlen(map[i]);
		if (this_len > longest_len)
			longest_len = this_len;
		i++;
	}
	return (longest_len);
}

/**
 * swaps two strings (from an array) and frees the original one.
 */
static void ft_swap_strings(t_data *data, char *new_line, int i)
{
	char *temp;

	temp = data->map[i];
	data->map[i] = new_line;
	free(temp);
}

/**
 * Appends spaces to a line if it was deemed to be too short. It creates
 * a new string of only spaces that is how_many chars long, null terminates
 * it, then calls ft_strjoin to join it together with the original string. 
 * 
 * The result is then swapped with the original string in the map array and
 * both the previous map line and the temp spaces string get freed.
 */
void ft_append_spaces(t_data *data, int i, int how_many)
{
	int j;
	char *temp;
	char *spaces;

	j = 0;
	spaces = (char *)malloc(sizeof(char) * how_many + 1);
	if (!spaces)
	{
		ft_free_data(data);
		exit(err_print("Data normalisation error(malloc)", EXIT_FAILURE));
	}
	while (j < how_many)
	{
		spaces[j] = ' ';
		j++;
	}
	spaces[j] = '\0';
	temp = ft_strjoin(data->map[i], spaces);
	if (!temp)
	{
		ft_free_data(data);
		exit(err_print("Data normalisation error(malloc)", EXIT_FAILURE));
	}
	free(spaces);
	ft_swap_strings(data, temp, i);
}
