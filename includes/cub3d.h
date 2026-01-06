/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-09 16:12:26 by vcerny            #+#    #+#             */
/*   Updated: 2025-12-09 16:12:26 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define HEIGTH 1080
# define WIDTH 1920
# define WINDOW_NAME "cub3D"
# define ROT_SPEED 2
# define MOV_SPEED 1
# define MOV_FAST 2
# define FOV 1.047
# define MINIMAP_TILE_TEXTURE_SIZE 32
# define FRAME_COUNTER 30
# define PLAYER_RADIUS_MINIMAP 7
# define PLAYER_COLISION_RADIUS 0.2
# define VIEWPORT_WIDTH 1280
# define VIEWPORT_HEIGTH 720
# define MINI_WIDTH 300
# define MINI_HEIGTH 300

# define MINIMAP_FLOOR "assets/map_floor.xpm"
# define MINIMAP_WALL "assets/map_wall.xpm"
# define MINIMAP_ARROW "assets/arrow.xpm"

typedef struct s_coords
{
	int					x1;
	int					y1;
	int					x0;
	int					y0;
}						t_coords;

typedef struct s_positions_check
{
	double				radius;
	double				delta_x;
	double				delta_y;
	double				probe_x;
	double				probe_y;
}						t_pos_check;

typedef struct s_dir
{
	double				dx;
	double				dy;
}						t_dir;

typedef struct s_pos
{
	double				pos_x;
	double				pos_y;
}						t_pos;

typedef struct s_buttons
{
	bool				w;
	bool				s;
	bool				a;
	bool				d;
	bool				left;
	bool				right;
	bool				shift;
}						t_buttons;

typedef struct s_img_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img_data;

typedef struct s_texture_copy
{
	int					i;
	int					j;
	int					x;
	int					y;
}						t_t_copy;

typedef struct s_data
{
	int					frame_counter;
	long long			time_d_compound;
	int					fps;
	char				*fps_string;
	char				*path_no;
	char				*path_so;
	char				*path_we;
	char				*path_ea;
	char				*string_f_color;
	char				*string_c_color;
	void				*image_map_wall;
	void				*image_map_floor;
	void				*image_map_player;
	void				*image_no;
	void				*image_so;
	void				*image_we;
	void				*image_ea;
	void				*image_minimap;
	char				initial_orientation;
	double				player_pos_x;
	double				player_pos_y;
	uint32_t			floor_color;
	uint32_t			ceiling_color;
	void				*mlx;
	void				*window;
	void				*image_to_window;
	char				**map;
	int					map_width;
	int					map_heigth;
	int					texture_heigth;
	int					texture_width;
	int					mini_texture_heigth;
	int					mini_texture_width;
	int					arr_heigth;
	int					arr_width;
	long long			last_time;
	t_buttons			buttons;
	t_dir				dir;
	t_dir				plane;
	int					map_started;
	int					map_ended;
}						t_data;

typedef struct s_cub_data
{
	long long			time_d;
	struct timeval		tv;
	t_pos				new_pos;
	t_dir				new_dir;
	t_dir				new_plane;
}						t_cub_data;

typedef struct s_update_position
{
	double				step;
	double				unit_len;
	t_pos				intent;
	t_pos				new_pos;
}						t_up_pos;

typedef struct s_player_min_pos
{
	int					x;
	int					y;
}						t_player_mini_pos;

typedef struct s_vertex
{
	int					x;
	int					y;
}						t_vertex;

typedef struct s_minimap
{
	t_player_mini_pos	p_pos;
	t_img_data			to_win_data;
	t_img_data			minimap_data;
	int					bytes_pp;
	int					dy;
	int					src_x0;
	int					src_y0;
	int					dst_x0;
	int					dst_y0;
	void				*src_row_ptr;
	void				*dst_row_ptr;
	int					src_y;
	int					dst_y;
	int					want_x0;
	int					want_y0;
	int					want_w;
	int					want_h;
	int					want_x1;
	int					want_y1;
	int					src_x1;
	int					src_y1;
	int					copy_src_x0;
	int					copy_src_y0;
	int					copy_src_x1;
	int					copy_src_y1;
	int					copy_w;
	int					copy_h;
	int					dst_copy_x0;
	int					dst_copy_y0;
}						t_minimap;

typedef struct s_raycast
{
	t_img_data			idata;
	t_img_data			north;
	t_img_data			south;
	t_img_data			east;
	t_img_data			west;
	t_img_data			tex_img;
	int					x_offset;
	int					y_offset;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_heigth;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	int					tex_x;
	int					tex_y;
	double				step;
	double				tex_pos;
	uint32_t			color;
}						t_raycast;

// init_source folder

void					ft_read_from_file(int fd, t_data *data);
void					ft_add_to_map(t_data *data, char *new_row);
void					ft_free_data(t_data *data);
int						err_print(char *msg, int exit_code);
bool					arg_check(char *arg);
void					ft_init_data(t_data *data);
void					ft_append_spaces(t_data *data, int i, int how_many);
bool					ft_map_char_check(t_data *data);
int						ft_get_longest_line_len(char **map);
bool					ft_map_check(t_data *data);
bool					ft_textures_check(t_data *data);
int						ft_init(int ac, char **av, t_data *data);
int						ft_init_buttons(t_data *data);
bool					ft_set_colors(t_data *data);
bool					ft_set_initial_position(t_data *data);
bool					ft_border_check(char **map, int width, int heigth,
							t_data *data);
void					ft_free_get_next(int fd);
void					ft_map_space_error_exit(int fd, t_data *data,
							char *temp);
bool					ft_is_map(char *s);

// textures_init folder

bool					ft_make_minimap(t_data *data);
bool					ft_load_images(t_data *data);
int						ft_mlx_window_innit(t_data *data);

// runtime folder

int						ft_err_terminate(t_data *data, char *err_msg);
int						ft_terminate(t_data *data);
int						ft_key_press(int keysym, t_data *data);
int						ft_key_release(int keysym, t_data *data);
void					custom_mlx_pixel_put(t_img_data *img_data, int x, int y,
							int color);
void					ft_draw_lines(t_coords *coords, t_img_data *img_data,
							int color);
void					ft_put_minimap_to_image(t_data *data);
void					ft_put_fps_on_screen(t_data *data, t_cub_data *c_data);
void					ft_prefill_minimap(t_minimap *map);
void					ft_put_player_on_minimap(int dst_y0, t_data *data,
							t_img_data to_win_data);
t_player_mini_pos		ft_get_minimap_player_pos(t_data *data);
bool					ft_update_vector(t_data *data, t_cub_data *c_data);
bool					ft_update_position(t_data *data, t_cub_data *c_data);
int						ft_reset_time_delta(t_data *data);
void					ft_raycast_ddm(t_data *data, t_raycast *r_data);
void					ft_raycast_colision_vals(t_data *data,
							t_raycast *r_data);
void					ft_raycast_set_current_texture(t_raycast *r_data);
void					ft_raycast_draw_column(t_data *data, t_raycast *r_data,
							int i);
double					ft_get_delta_dist(double ray_dir);
uint32_t				ft_get_pixel_color(t_img_data *img, int x, int y,
							t_data *data);
void					ft_raycast_initial_data(t_data *data,
							t_raycast *r_data);
void					ft_raycast_set_vals_in_loop(t_data *data,
							t_raycast *r_data, int i);
void					ft_raycast_set_step_x_n_y(t_data *data,
							t_raycast *r_data);

#endif