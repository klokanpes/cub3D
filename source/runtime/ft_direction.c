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
 * returns the new direction vector of the player based on
 * the original direction and delta theta. 
 * 
 * Adapted from: https://lodev.org/cgtutor/raycasting.html
 */
static t_dir	ft_get_dir(float d_th, t_dir orig_dir)
{
	t_dir	ret;

	ret.dx = (orig_dir.dx * cos(d_th)) - (orig_dir.dy * sin(d_th));
	ret.dy = (orig_dir.dx * sin(d_th)) + (orig_dir.dy * cos(d_th));
	return (ret);
}

/**
 * Sets plane based on the player vector. It is a perpendicular
 * vector to the players direction and it enables the raycaster
 * to cast a ray for each screen pixel column. It controls the Field Of View.
 */
static void	ft_set_plane(t_cub_data *c_data)
{
	double	plane_len;

	plane_len = tan(FOV / 2);
	c_data->new_plane.dx = -c_data->new_dir.dy * plane_len;
	c_data->new_plane.dy = c_data->new_dir.dx * plane_len;
}

/**
 * These functions (above) parse the rotation movement to
 * currently be applied and apply it.
 *
 * Firstly, it gives the old value to the new one (different
 * structs -> so as to not loose data if there is nothing to be done).
 *
 * Then, if no button is pressed (left|right arrow), it returns right
 * away -> nothing to be done here. Also, it disregards both buttons
 * being pressed at the same time.
 *
 * else, it calculates the d_th(delta theta) angular velocity, by
 * multiplying ROT_SPEED(in radians/second) by time_delta. So that rotation
 * speed is the same no matter the framerate. Basically, how much
 * rotation to apply in each frame.
 * 
 * Then it applies the rotation by calculating the new forward vector
 * based on the button being pressed. (left arrow gets -delta theta)
 * 
 * Then it sets the new plane (perpendicular vector) and returns.
 */
bool	ft_update_vector(t_data *data, t_cub_data *c_data)
{
	double	d_th;

	c_data->new_dir.dx = data->dir.dx;
	c_data->new_dir.dy = data->dir.dy;
	c_data->new_plane.dx = data->plane.dx;
	c_data->new_plane.dy = data->plane.dy;
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
