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
 * Actual rendering logic lives here, all frames are made here,
 * movement logic lives here.
 */
int	cub3d(t_data *data)
{
	t_cub_data	c_data;
	t_img_data	idata;
	int			x_offset;
	int			y_offset;

	gettimeofday(&c_data.tv, 0);
	c_data.time_d = (c_data.tv.tv_sec * 1000) + (c_data.tv.tv_usec / 1000)
		- data->last_time;
	if (c_data.time_d > 100) // to avoid big jumps on alt+tab etc
		c_data.time_d = 100;
	data->last_time = (c_data.tv.tv_sec * 1000) + (c_data.tv.tv_usec / 1000);
	if (ft_update_vector(data, &c_data))
	{
		data->dir = c_data.new_dir;
		data->plane = c_data.new_plane;
	}
	if (ft_update_position(data, &c_data))
	{
		data->player_pos_x = c_data.new_pos.pos_x;
		data->player_pos_y = c_data.new_pos.pos_y;
	}
	/**
	* @todo raycasting
	*/
	/**
	* Placeholder for the 3D
	*/
	x_offset = WIDTH / 2 - 1280 / 2;
	y_offset = 50;
	idata.addr = mlx_get_data_addr(data->image_to_window, &idata.bits_per_pixel,
			&idata.line_length, &idata.endian);
	for (int i = x_offset; i < 1280 + x_offset; i++)
	{
		for (int j = y_offset; j < 720 + y_offset; j++)
		{
			custom_mlx_pixel_put(&idata, i, j, data->floor_color);
		}
	}
	// ft_raycasting();
	ft_put_minimap_to_image(data);
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->image_to_window, 0,
		0);
	ft_put_fps_on_screen(data, &c_data);
	return (0);
}

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
	// start counting time from now!
	ft_reset_time_delta(&data);
	mlx_do_key_autorepeatoff(data.mlx);
	// so that a key press does not generate multiple instances of the same thing
	mlx_hook(data.window, 2, 1L << 0, ft_key_press, &data);
	// generic keyhook for presses
	mlx_hook(data.window, 3, 1L << 1, ft_key_release, &data);
	// keyhook for releases
	mlx_hook(data.window, 10, 1L << 21, ft_init_buttons, &data);
	// to reset buttons when window focus is lost
	mlx_hook(data.window, 9, 1L << 21, ft_reset_time_delta, &data);
	// start counting delta time from now (now big move on returning to window)
	mlx_hook(data.window, 17, 0, ft_terminate, &data);
	// so that it is possible to close with a cross icon
	mlx_loop_hook(data.mlx, cub3d, &data);
	mlx_loop(data.mlx);
}
