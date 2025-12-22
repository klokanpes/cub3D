/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 17:48:03 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-20 17:48:03 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @todo COMMENTS! SO MUCH FUCKING HAPPENING HERE!
 */
static t_dir	ft_get_dir(float d_th, t_dir orig_dir)
{
	t_dir	ret;

	ret.dx = (orig_dir.dx * cos(d_th)) - (orig_dir.dy * sin(d_th));
	ret.dy = (orig_dir.dx * sin(d_th)) + (orig_dir.dy * cos(d_th));
	return (ret);
}

/**
 * @todo COMMENTS! SO MUCH FUCKING HAPPENING HERE!
 */
static void	ft_set_plane(t_cub_data *c_data)
{
	double	plane_len;

	plane_len = tan(FOV / 2);
	c_data->new_plane.dx = -c_data->new_dir.dy * plane_len;
	c_data->new_plane.dy = c_data->new_dir.dx * plane_len;
}

/**
 * @todo COMMENTS! SO MUCH FUCKING HAPPENING HERE!
 */
bool	ft_update_vector(t_data *data, t_cub_data *c_data)
{
	double	d_th;

	c_data->new_dir.dx = data->dir.dx;
	c_data->new_dir.dy = data->dir.dy;
	if ((!data->buttons.left && !data->buttons.right) || (data->buttons.left
			&& data->buttons.right))
		return (false);
	// keep it in ms,change to s for computation
	d_th = ROT_SPEED * (c_data->time_d / 1000.0);
	if (data->buttons.left)
		c_data->new_dir = ft_get_dir(d_th * -1.0, c_data->new_dir);
	else if (data->buttons.right)
		c_data->new_dir = ft_get_dir(d_th, c_data->new_dir);
	ft_set_plane(c_data);
	return (true);
}