/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-09 10:37:58 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-09 10:37:58 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Main raycasting func
 * sets initial values, sets the step, runs the DDM algorithm (colisions),
 * then sets the colision values and drawing values (where and what),
 * picks the texture to choose from, and lastly draws one column of pixels onto
 * the image buffer (image to window)
 *
 * The main ideas come from:
 * https://lodev.org/cgtutor/raycasting.html
 */
void	ft_raycasting(t_data *data)
{
	t_raycast	r_data;
	int			i;

	ft_raycast_initial_data(data, &r_data);
	i = 0;
	while (i < VIEWPORT_WIDTH)
	{
		ft_raycast_set_vals_in_loop(data, &r_data, i);
		ft_raycast_set_step_x_n_y(data, &r_data);
		ft_raycast_ddm(data, &r_data);
		ft_raycast_colision_vals(data, &r_data);
		ft_raycast_set_current_texture(&r_data);
		ft_raycast_draw_column(data, &r_data, i);
		i++;
	}
}

/**
 * Actual rendering logic lives here, all frames are made here,
 * movement logic lives here.
 *
 * Firstly, get current time to calculate time_delta, the time difference
 * between this frame and the previous frame. This is there so that
 * the gameplay loop speed is consistent. Without it, the player would
 * be able to run very fast with high FPS, and slow otherwise. This
 * makes the movement speed the same, no matter what.
 * Then normalize it, if it became a very big number (should not happen, since
 * there is a hook set for that case, but...), it could also happen with very
 * low fps.
 * Then set the current time as the last time for the next frame time_delta.
 * Then movement happens. Firstly the vector is updated based on input (turning
 * left and right), then WSAD keys.
 * Then the data written by these functions are put into the data struct to be
 * used in raycasting.
 * Then raycasting happens, then the minimap is partly overlayed over the
 * raycasted image (I like it better this way visually), then clear the
 * window in between frames, then put the image to window(always only one
 * image buffer), mlx_do_sync is there to slow the computed performance, since
 * mlx_put_image_to_window is asynchronous and only eques the task, the FPS
 * counter is not as reliable without it.- mlx_do_sync waits for the image to
 * actually be pushed to window.
 * Lastly, put FPS on the screen (there is no ghosting because the window is
 * cleared every frame).
 * Return 0 is there only becase the mlx_loop_hook requires this function
 * to return an int.
 *
 * The normalisation step with time_d is to avoid big jumps on alt+tab etc
 */
int	cub3d(t_data *data)
{
	t_cub_data	c_data;

	gettimeofday(&c_data.tv, 0);
	c_data.time_d = (c_data.tv.tv_sec * 1000) + (c_data.tv.tv_usec / 1000)
		- data->last_time;
	if (c_data.time_d > 100)
		c_data.time_d = 100;
	data->last_time = (c_data.tv.tv_sec * 1000) + (c_data.tv.tv_usec / 1000);
	ft_update_vector(data, &c_data);
	ft_update_position(data, &c_data);
	data->dir = c_data.new_dir;
	data->plane = c_data.new_plane;
	data->player_pos_x = c_data.new_pos.pos_x;
	data->player_pos_y = c_data.new_pos.pos_y;
	ft_raycasting(data);
	ft_put_minimap_to_image(data);
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->image_to_window, 0,
		0);
	mlx_do_sync(data->mlx);
	ft_put_fps_on_screen(data, &c_data);
	return (0);
}

/**
 * Adapted from: https://harm-smits.github.io/42docs/libs/minilibx/events.html
 *
 * The idea is to bond specific behaviours to specific actions.
 * The first one captures key presses(1L << 0)
 * The second one captures key releases (1L << 1)
 * Third and fourth ones (1L << 21) happen on focus change(like alt tabing),
 * event
 * 10 is focus loss, event 9 is regain focus. On focus loss all keys are
 * set to false, meaning the game is not accepting input when the window
 * is not at the top. On regaining focus the time delta is re-set, so
 * that the movement never breaks, otherwise since movement speed in each
 * frame equals time_delta * MOVEMENT_SPEED, it could result in a giant, out
 * of bounds step.
 * The last hook is for enabling the cross button at the top of a window to
 * close the game.
 */
void	ft_set_hooks(t_data *data)
{
	mlx_hook(data->window, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->window, 3, 1L << 1, ft_key_release, data);
	mlx_hook(data->window, 10, 1L << 21, ft_init_buttons, data);
	mlx_hook(data->window, 9, 1L << 21, ft_reset_time_delta, data);
	mlx_hook(data->window, 17, 0, ft_terminate, data);
}

/**
 * The general flow is to parse and check input via ft_init, then
 * initialize the window and mlx pointers and start up the window.
 * The it loads the textures into memory (this needs the mlx pointer),
 * so it has to happen after window/mlx init.
 * Then, create a new image buffer for writing into, start counting time,
 * mlx_do_key_autorepeatoff is there to disable multiple key press
 * events when a key gets pressed (if it is not there, a key being pressed
 * generates an infinite loop of presses and releases, I only want to
 * capture the change when it happens and set appropriate flags...)
 * Then, set the hooks (for key presses and releases, for focus changes and
 * for the cross button to close the app)
 * Then hook the cub3d function into the mlx loop, meaning that the mlx_loop
 * will run the cub3d func on each itteration, then lastly, the mlx_loop
 * to keep drawing frames until something happens...
 */
int	main(int ac, char **av)
{
	t_data	data;

	if (ft_init(ac, av, &data) != 0)
	{
		ft_free_data(&data);
		return (err_print("Something went wrong", EXIT_FAILURE));
	}
	ft_mlx_window_innit(&data);
	if (!ft_load_images(&data))
		ft_err_terminate(&data, "Textures error");
	data.image_to_window = mlx_new_image(data.mlx, WIDTH, HEIGTH);
	if (!data.image_to_window)
		ft_err_terminate(&data, "Image error");
	ft_reset_time_delta(&data);
	mlx_do_key_autorepeatoff(data.mlx);
	ft_set_hooks(&data);
	mlx_loop_hook(data.mlx, cub3d, &data);
	mlx_loop(data.mlx);
}
