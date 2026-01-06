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
 * A probe is basically the added new position (wanted) with the
 * value of the radius
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
 * This function checks the wanted new player position agains
 *  the map. If there were to be a colision with the wall, the player
 * cant move there, so that has to be checked. Both axis are tried 
 * independently which results in a sliding motion along walls without
 * any physics logic.
 * The player is also being treated as a circle, a radius is being added 
 * to the player so that it is not possible to clip through corners etc.
 * 
 * Also, the probe is being checked in two places around the player to
 * prevent being stuck in corners.
 * 
 * The radius also prevents the player to go really close to a wall which
 * is visually not really pretty
 */
static void	ft_check_new_positions(t_pos *new_pos, t_data *data,
		t_cub_data *c_data)
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
 * adds all the intended moves together based on which keys are pressed.
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

void ft_normalize_unit_len(t_up_pos *pos)
{
	pos->intent.pos_x *= 1.0 / pos->unit_len;
	pos->intent.pos_y *= 1.0 / pos->unit_len;
}

/**
 * Computes the movement of the player via WSAD keys and computes
 * the new position the player would go to. Then it tries to apply it, 
 * if the player were to hit a wall (go into it), nothing happens.
 * 
 * First, it copies the original position (so that no data is lost), 
 * then it checks whether and of the WSAD keys are pressed. If not,
 * nothing to be done here (return).
 * 
 * Then it initializes the intended positions to 0, checks whether
 * shift is pressed, which changes the step(speed) -> calculated
 * via time_delta and movement speed constants.
 * 
 * Then it sets the intended movement position(combinig all
 * pressed buttons together (opposing buttons approximately cancel
 * each other out)).
 * Then, if no intent was found, return (nothing to do, they canceled
 * each other out -> probably wont happen perfectly since they are 
 * float values and they will not be equal to 0 but one can dream).
 * 
 * Then unit len is computed and normalized in case it was a big number.
 * Unit len is basically a triangle where I want to end up.
 * 
 * Then the new position(wanted) is updated and checked for correctness.
 */
bool	ft_update_position(t_data *data, t_cub_data *c_data)
{
	t_up_pos	pos;

	c_data->new_pos.pos_x = data->player_pos_x;
	c_data->new_pos.pos_y = data->player_pos_y;
	pos.new_pos.pos_y = data->player_pos_y;
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
		ft_normalize_unit_len(&pos);
	pos.new_pos.pos_x = data->player_pos_x + pos.intent.pos_x * pos.step;
	pos.new_pos.pos_y = data->player_pos_y + pos.intent.pos_y * pos.step;
	ft_check_new_positions(&pos.new_pos, data, c_data);
	return (true);
}
