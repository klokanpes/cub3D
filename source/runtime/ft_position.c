/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 17:49:52 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-20 17:49:52 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Helper for setting the probes
 * @todo MORE FUCKING COMMENTS!!!
 */
static void	ft_set_probes(t_pos_check *pos, t_pos *new_pos)
{
	if (pos->delta_x > 0)
		pos->probe_x = new_pos->pos_x + pos->radius;
	else
		pos->probe_x = new_pos->pos_x - pos->radius;
	if (pos->delta_y > 0)
		pos->probe_y = new_pos->pos_y + pos->radius;
	else
		pos->probe_y = new_pos->pos_y - pos->radius;
}

/**
 * @todo COMMENTS! SO MUCH FUCKING HAPPENING HERE!
 */
static void	ft_check_new_positions(t_pos *new_pos, t_data *data, t_cub_data *c_data)
{
	t_pos_check	pos;

	pos.delta_x = new_pos->pos_x - data->player_pos_x;
	pos.delta_y = new_pos->pos_y - data->player_pos_y;
	c_data->new_pos.pos_y = data->player_pos_y;
	c_data->new_pos.pos_x = data->player_pos_x;
	pos.radius = PLAYER_COLISION_RADIUS;
	ft_set_probes(&pos, new_pos);
	if (pos.delta_y != 0.0)
	{
		if (data->map[(int)pos.probe_y][(int)(data->player_pos_x
				+ pos.radius)] == '0'
			&& data->map[(int)pos.probe_y][(int)(data->player_pos_x
				- pos.radius)] == '0')
			c_data->new_pos.pos_y = new_pos->pos_y;
	}
	if (pos.delta_x != 0.0)
	{
		if (data->map[(int)(c_data->new_pos.pos_y
				+ pos.radius)][(int)pos.probe_x] == '0'
			&& data->map[(int)(c_data->new_pos.pos_y
				- pos.radius)][(int)pos.probe_x] == '0')
			c_data->new_pos.pos_x = new_pos->pos_x;
	}
}

/**
 * @todo ADD FUCKING COMMENTS!!!
 */
static void	ft_set_intent(t_data *data, t_cub_data *c_data, t_up_pos *pos)
{
	if (data->buttons.w)
	{
		pos->intent.pos_x += c_data->new_dir.dx;
		pos->intent.pos_y += c_data->new_dir.dy;
	}
	if (data->buttons.s)
	{
		pos->intent.pos_x -= c_data->new_dir.dx;
		pos->intent.pos_y -= c_data->new_dir.dy;
	}
	if (data->buttons.a)
	{
		pos->intent.pos_x += c_data->new_dir.dy;
		pos->intent.pos_y -= c_data->new_dir.dx;
	}
	if (data->buttons.d)
	{
		pos->intent.pos_x -= c_data->new_dir.dy;
		pos->intent.pos_y += c_data->new_dir.dx;
	}
}

/**
 * @todo COMMENTS! SO MUCH FUCKING HAPPENING HERE!
 */
bool	ft_update_position(t_data *data, t_cub_data *c_data)
{
	t_up_pos	pos;

	if (!data->buttons.w && !data->buttons.s && !data->buttons.a
		&& !data->buttons.d)
		return (false);
	pos.intent.pos_x = 0;
	pos.intent.pos_y = 0;
	if (!data->buttons.shift)
		pos.step = (c_data->time_d / 1000.0) * MOV_SPEED;
	else
		pos.step = (c_data->time_d / 1000.0) * MOV_FAST;
	ft_set_intent(data, c_data, &pos);
	if (pos.intent.pos_x == 0.0 && pos.intent.pos_y == 0.0)
		return (false);
	pos.unit_len = sqrt(pos.intent.pos_x * pos.intent.pos_x + pos.intent.pos_y
			* pos.intent.pos_y);
	if (pos.unit_len > 0)
	{
		pos.intent.pos_x *= 1.0 / pos.unit_len;
		pos.intent.pos_y *= 1.0 / pos.unit_len;
	}
	pos.new_pos.pos_x = data->player_pos_x + pos.intent.pos_x * pos.step;
	pos.new_pos.pos_y = data->player_pos_y + pos.intent.pos_y * pos.step;
	ft_check_new_positions(&pos.new_pos, data, c_data);
	return (true);
}
