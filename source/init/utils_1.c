/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 16:31:04 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-13 16:31:04 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Checks arg len (argv[1]) and checks whether it has the correct ending
 */
bool	arg_check(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len < 5)
		return (false);
	if (arg[len - 1] != 'b' || arg[len - 2] != 'u' || arg[len - 3] != 'c'
		|| arg[len - 4] != '.')
		return (false);
	return (true);
}

int	ft_init_buttons(t_data *data)
{
	data->buttons.w = false;
	data->buttons.s = false;
	data->buttons.a = false;
	data->buttons.d = false;
	data->buttons.left = false;
	data->buttons.right = false;
	data->buttons.shift = false;
	data->fps_string = NULL;
	data->mini_texture_heigth = 32;
	data->mini_texture_width = 32;
	data->map_started = 0;
	data->map_ended = 0;
	return (0);
}

/**
 * initializes all in data to NULL so that I can detect whether it has
 * been successfully allocated while freeing
 */
void	ft_init_data(t_data *data)
{
	data->image_map_floor = NULL;
	data->image_map_player = NULL;
	data->image_map_wall = NULL;
	data->image_ea = NULL;
	data->image_no = NULL;
	data->image_so = NULL;
	data->image_we = NULL;
	data->image_to_window = NULL;
	data->map = NULL;
	data->path_ea = NULL;
	data->path_no = NULL;
	data->path_so = NULL;
	data->path_we = NULL;
	data->string_c_color = NULL;
	data->string_f_color = NULL;
	data->image_minimap = NULL;
	data->image_to_window = NULL;
	data->texture_heigth = 64;
	data->texture_width = 64;
	data->initial_orientation = 'X';
	ft_init_buttons(data);
	data->time_d_compound = 0;
	data->frame_counter = 0;
}

/**
 * Checks whether a parsed line from the .cub file is a map line
 */
bool ft_is_map(char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '1' && s[i] != '0' && s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
			flag++;
		i++;
	}
	if (flag > 0)
		return (true);
	return (false);
}
