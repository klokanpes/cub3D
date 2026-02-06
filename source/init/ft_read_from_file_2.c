/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-06 17:49:29 by vcerny            #+#    #+#             */
/*   Updated: 2026-02-06 17:49:29 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_and_print_error(t_data *data, char *temp, char *msg, int fd)
{
	free(temp);
	ft_free_data(data);
	ft_free_get_next(fd);
	close(fd);
	exit(err_print(msg, EXIT_FAILURE));
}

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
 * basically it dynamically grows the map arr, making sure to always
 * null terminate it.
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
