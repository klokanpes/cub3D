/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 20:24:26 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-13 20:24:26 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Actually checks also that there is meaningful content in the textures
 * paths, not only .xpm
 */
static bool	ft_check_file_type(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (false);
	if (path[len - 1] != 'm' || path[len - 2] != 'p' || path[len - 3] != 'x'
		|| path[len - 4] != '.')
		return (false);
	return (true);
}

/**
 * Checks whether the textures that were in the input file have .xpm at the
 * end. This is the only supported format by minilibx, so nothing else
 * is allowed here. (We could fail later (when trying to parse them),
 * but let's exit cleanly now)
 */
bool	ft_textures_check(t_data *data)
{
	if (!data->path_no || !data->path_so || !data->path_ea || !data->path_we)
		return (false);
	if (!ft_check_file_type(data->path_no) || !ft_check_file_type(data->path_so)
		|| !ft_check_file_type(data->path_ea)
		|| !ft_check_file_type(data->path_we) || !data->string_c_color
		|| !data->string_f_color)
		return (false);
	return (true);
}
