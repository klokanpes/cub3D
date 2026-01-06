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

static void	ft_add_to_map_2(t_data *data, char *new_row, int *valid_rows)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (*valid_rows + 2));
	if (!temp)
	{
		ft_free_data(data);
		exit(err_print("Map reading error(malloc)", EXIT_FAILURE));
	}
	while (data->map[i])
	{
		temp[i] = data->map[i];
		i++;
	}
	temp[i] = new_row;
	temp[i + 1] = NULL;
	free(data->map);
	data->map = temp;
	(*valid_rows)++;
}

/**
 * This funcrion is called when a map row is encountered, it allocates space 
 * for one new row in the map array and adds it there
 * 
 * basically it dynamically grows the map arr, making sure to always null terminate it. 
 */
void	ft_add_to_map(t_data *data, char *new_row)
{
	static int	valid_rows = 0;

	if (valid_rows == 0)
	{
		data->map = (char **)malloc(sizeof(char *) * 2);
		if (!data->map)
		{
			ft_free_data(data);
			exit(err_print("Map reading error(malloc)", EXIT_FAILURE));
		}
		data->map[0] = new_row;
		data->map[1] = NULL;
		valid_rows++;
	}
	else
		ft_add_to_map_2(data, new_row, &valid_rows);
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
	else
	{
		if (data->map_ended == 1)
			ft_map_space_error_exit(fd, data, temp);
		ft_add_to_map(data, temp);
		if (data->map_started == 0)
			data->map_started = 1;
		ft_read_from_file(fd, data);
	}
}

static void	ft_read_from_file_2(int fd, t_data *data, char *temp)
{
	if (temp[0] == 'E' && temp[1] == 'A')
	{
		data->path_ea = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'W' && temp[1] == 'E')
	{
		data->path_we = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'F')
	{
		data->string_f_color = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'C')
	{
		data->string_c_color = temp;
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
	char *temp;
	char *temp_temp;

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
		data->path_no = temp;
		ft_read_from_file(fd, data);
	}
	else if (temp[0] == 'S' && temp[1] == 'O')
	{
		data->path_so = temp;
		ft_read_from_file(fd, data);
	}
	else
		ft_read_from_file_2(fd, data, temp);
}
