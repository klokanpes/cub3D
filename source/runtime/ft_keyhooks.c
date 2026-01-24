/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 19:01:41 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-15 19:01:41 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Keyhook function to log key presses
 *
 * When I key is pressed, the state is saved
 */
int	ft_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_terminate(data);
	if (keysym == XK_w)
		data->buttons.w = true;
	if (keysym == XK_s)
		data->buttons.s = true;
	if (keysym == XK_a)
		data->buttons.a = true;
	if (keysym == XK_d)
		data->buttons.d = true;
	if (keysym == XK_Shift_L)
		data->buttons.shift = true;
	if (keysym == XK_Left)
		data->buttons.left = true;
	if (keysym == XK_Right)
		data->buttons.right = true;
	return (0);
}

/**
 * Keyhook function to log key releases
 *
 * When a key is released, the state is reset
 */
int	ft_key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->buttons.w = false;
	if (keysym == XK_s)
		data->buttons.s = false;
	if (keysym == XK_a)
		data->buttons.a = false;
	if (keysym == XK_d)
		data->buttons.d = false;
	if (keysym == XK_Shift_L)
		data->buttons.shift = false;
	if (keysym == XK_Left)
		data->buttons.left = false;
	if (keysym == XK_Right)
		data->buttons.right = false;
	return (0);
}
