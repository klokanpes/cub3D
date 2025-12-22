/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 20:25:49 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-13 20:25:49 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Tries to open every texture to check paths. If not successful, it frees data 
 * and exits as non-existent textures would create a segfault while trying
 * to load images
 */
static void ft_check_textures(t_data *data)
{
	int fd;
	int flag;

	flag = 0;
	fd = open(data->path_no, O_RDONLY);
	if (fd < 0)
		flag++;
	close(fd);
	fd = open(data->path_so, O_RDONLY);
	if (fd < 0)
		flag++;
	close(fd);
	fd = open (data->path_ea, O_RDONLY);
	if (fd < 0)
		flag++;
	close(fd);
	fd = open (data->path_we, O_RDONLY);
	if (fd < 0)
		flag++;
	close(fd);
	if (flag > 0)
	{
		ft_free_data(data);
		exit(err_print("Textures path not correct", EXIT_FAILURE));
	}
}

static int ft_clean_up_input_2(t_data *data)
{
	char *temp;

	temp = ft_strtrim(data->string_c_color, "C ");
	if (!temp)
		return (1);
	free(data->string_c_color);
	data->string_c_color = temp;
	temp = ft_strtrim(data->string_f_color, "F ");
	if (!temp)
		return (1);
	free(data->string_f_color);
	data->string_f_color = temp;
	ft_check_textures(data);
	return (0);
}

/**
 * Trims all input values so that no markers are left in them
 */
static int ft_clean_up_input(t_data *data)
{
	char *temp;

	temp = ft_strtrim(data->path_no, "NO ");
	if (!temp)
		return (1);
	free(data->path_no);
	data->path_no = temp;
	temp = ft_strtrim(data->path_so, "SO ");
	if (!temp)
		return (1);
	free(data->path_so);
	data->path_so = temp;
	temp = ft_strtrim(data->path_ea, "EA ");
	if (!temp)
		return (1);
	free(data->path_ea);
	data->path_ea = temp;
	temp = ft_strtrim(data->path_we, "WE ");
	if (!temp)
		return (1);
	free(data->path_we);
	data->path_we = temp;
	return (ft_clean_up_input_2(data));
}

/**
 * Continue with initialization of values in data.
 * Specifically cleans up input from markers, sets time, 
 * and sets initial angle based on initial position in map.
 */
static int ft_init_2(t_data *data)
{
	if (ft_clean_up_input(data))
	{
		ft_free_data(data);
		exit(err_print("Input cleanup error", EXIT_FAILURE));
	}
	if (!ft_set_colors(data))
	{
		ft_free_data(data);
		exit(err_print("Color input error", EXIT_FAILURE));
	}
	if (!ft_set_initial_position(data))
	{
		ft_free_data(data);
		exit(err_print("Initial position error", EXIT_FAILURE));
	}
	return (0);
}

/**
 * Main initializer, open file, parse strings, check map...
 */
int	ft_init(int ac, char **av, t_data *data)
{
	int	fd;

	ft_init_data(data);
	if (ac != 2)
		exit(err_print("Usage: ./cub3d input_file.cub", EXIT_FAILURE));
	if (!arg_check(av[1]))
		exit(err_print("Usage: ./cub3d input_file.cub", EXIT_FAILURE));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(err_print("Input file error", EXIT_FAILURE));
	ft_read_from_file(fd, data);
	close(fd);
	if (!ft_map_check(data))
	{
		ft_free_data(data);
		exit(err_print("Map error", EXIT_FAILURE));
	}
	if (!ft_textures_check(data))
	{
		ft_free_data(data);
		exit(err_print("Textures error. Usage: texture.xpm", EXIT_FAILURE));
	}
	return (ft_init_2(data));
}
