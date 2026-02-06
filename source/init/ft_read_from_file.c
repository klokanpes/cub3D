/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-11 21:40:22 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-11 21:40:22 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_read_from_file_4(int fd, t_data *data, char *temp)
{
	if (data->map_ended == 1)
		ft_map_space_error_exit(fd, data, temp);
	ft_add_to_map(data, temp);
	if (data->map_started == 0)
		data->map_started = 1;
	ft_read_from_file(fd, data);
}

/**
 * Remembers states about the map parsing being started and finished.
 * If it was finished but there is another map line, it exits
 * the program with an error.
 */
static void	ft_read_from_file_3(int fd, t_data *data, char *temp)
{
	if (temp[0] == '\0')
	{
		if (data->map_ended == 0 && data->map_started == 1)
			data->map_ended = 1;
		else if (data->map_ended == 1 && ft_is_map(temp))
			ft_map_space_error_exit(fd, data, temp);
		free(temp);
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'F')
	{
		if (data->string_f_color)
			ft_free_and_print_error(data, temp, "Double color", fd);
		data->string_f_color = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'C')
	{
		if (data->string_c_color)
			ft_free_and_print_error(data, temp, "Double color", fd);
		data->string_c_color = temp;
		ft_read_from_file(fd, data);
	}
	else
		ft_read_from_file_4(fd, data, temp);
}

static void	ft_read_from_file_2(int fd, t_data *data, char *temp)
{
	if (temp[0] == 'E' && temp[1] == 'A')
	{
		if (data->path_ea)
			ft_free_and_print_error(data, temp, "Double texture", fd);
		data->path_ea = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'S' && temp[1] == 'O')
	{
		if (data->path_so)
			ft_free_and_print_error(data, temp, "Double texture", fd);
		data->path_so = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'W' && temp[1] == 'E')
	{
		if (data->path_we)
			ft_free_and_print_error(data, temp, "Double texture", fd);
		data->path_we = temp;
		ft_read_from_file(fd, data);
	}
	else
		ft_read_from_file_3(fd, data, temp);
}

/**
 * Reads from the file from argv[1] and stores all results in data.
 * Reads the data recursively, each new call parses a new line from
 * the file via gnl, works with it, and recurses. On EOF it returns.
 *
 * Also, removes the trailing new lines
 */
void	ft_read_from_file(int fd, t_data *data)
{
	char	*temp;
	char	*temp_temp;

	temp = get_next_line(fd);
	if (!temp)
		return ;
	if (ft_strchr(temp, '\n'))
	{
		temp_temp = ft_strtrim(temp, "\n");
		free(temp);
		temp = temp_temp;
	}
	if (temp[0] == 'N' && temp[1] == 'O')
	{
		if (data->path_no)
			ft_free_and_print_error(data, temp, "Double texture", fd);
		data->path_no = temp;
		ft_read_from_file(fd, data);
	}
	else
		ft_read_from_file_2(fd, data, temp);
}
