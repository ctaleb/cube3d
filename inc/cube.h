/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:46:12 by ctaleb            #+#    #+#             */
/*   Updated: 2021/04/03 15:24:50 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "libft.h"
# include "mlx.h"

typedef struct	 s_map {
	char		**file;
	char		**grid;
	int			map_id;
	int			max_y;
	int			max_x;
	char		**dup;
	int			ratio;
	int			start_x;
	int			start_y;
	int			res_x;
	int			res_y;
	char		*north_t;
	char		*south_t;
	char		*east_t;
	char		*west_t;
	char		*sprite_t;
	char		*skybox_t;
	int			sprite_nb;
	int			file_len;
	int			floor_c;
	int			ceiling_c;
}				t_map;

typedef struct	s_input {
	int			forward;
	int			backward;
	int			strafe_l;
	int			strafe_r;
	int			rotate_l;
	int			rotate_r;
	int			crouch;
}				t_input;

typedef struct s_player {
	float		x;
	float		y;
	float		f_x;
	float		f_y;
	int			colour;
}				t_player;

typedef struct	s_image {
	void		*ptr;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_image;

typedef struct	s_ray {
	int			id;
	int			pos;
	float		nwall_x;
	float		nwall_y;
	int			shift_x;
	int			shift_y;
	float		s_x;
	float		s_y;
	float		n_x;
	float		n_y;
	float		dist_x;
	float		dist_y;
	int			side;
	int			u_wall;
	int			l_wall;
}				t_ray;

typedef struct	s_fov {
	int			fov;
	int			multi;
	float		cam_x;
	float		cam_y;
	float		*dist;
	float		mod;
	float		*shade;
}				t_fov;

typedef struct	s_texture {
	void		*ptr;
	int			*addr;
	char		*path;
	int			width;
	int			height;
	int			bpp;
	int			len;
	int			endian;
}				t_texture;

typedef struct	s_sprites {
	int			id;
	int			type;
	int			active;
	int			visible;
	float		x;
	float		y;
	float		dist;
	float		d_x;
	float		d_y;
	float		r_x;
	float		r_y;
	float		size_x;
	float		size_y;
	int			u_coord;
	int			b_coord;
	int			l_coord;
	int			r_coord;
	float		angle;
}				t_sprites;

typedef struct	s_mlx_parmas {
	void		*ptr;
	void		*win;
	int			save;
	t_image		*img;
	t_map		*map;
	t_texture	*n_txt;
	t_texture	*s_txt;
	t_texture	*e_txt;
	t_texture	*w_txt;
	t_texture	*sp_txt;
	t_texture	*skybox;
	t_player	*pl;
	t_ray		*r;
	t_fov		*f;
	t_sprites	**sp;
	t_input		*input;
}				t_mlx_params;

void			map_open(char *path, t_mlx_params *mlx);

int				file_len(char *path, t_mlx_params *mlx);
int				is_map(char *line);
int				analyne(t_map *map_data, char *line);
int				space_dig(char *line, int i, t_mlx_params *mlx);
int				space_comma(char *line, int i, t_mlx_params *mlx);

int				data_check(t_map *map_data);
void			start_check(t_map *map_data, t_mlx_params *mlx);
void			map_check(int x, int y, t_map *map_data, t_mlx_params *mlx);

void			map_data_init(t_mlx_params *mlx, char *path);
void			grid_init(t_mlx_params *mlx);
void			map_init(t_mlx_params *mlx);
void			img_init(t_mlx_params *mlx);
t_mlx_params	*mlx_data_init(int ac, char **av);
void			pl_init(t_mlx_params *mlx);
void			sprite_init(t_mlx_params *mlx);
void			fov_init(t_mlx_params *mlx);
void			ray_init(t_mlx_params *mlx);
void			texture_init(t_mlx_params *mlx);
void			input_init(t_mlx_params *mlx);

int				frame_gen(t_mlx_params *mlx);
void			my_mlx_pixel_put(t_mlx_params *mlx, int x, int y, int color);
void			my_mlx_multi_put(t_mlx_params *mlx, int x, int y, int color);
void			print_minimap(t_mlx_params *mlx);
void			put_map(int x, int y, t_mlx_params *mlx);
void			put_player(t_mlx_params *mlx);
void			rem_player(t_mlx_params *mlx);
void			put_camera(t_mlx_params *mlx);
void			rem_camera(t_mlx_params *mlx);
void			put_fov(t_mlx_params *mlx);

void			find_y(t_mlx_params *mlx);
void			find_x(t_mlx_params *mlx);
int				is_valid_coord(int shft_x, int shft_y, t_mlx_params *mlx);

void			ray_cannon(float fish, t_mlx_params *mlx);
void			sprite_check(t_mlx_params *mlx);
void			sprite_dist(t_mlx_params *mlx);
void			sprite_sort(t_mlx_params *mlx);
void			sprite_disable(int i, t_mlx_params *mlx);

void			sprite_reset(t_mlx_params *mlx);
void			sprite_xpos(int i, t_mlx_params *mlx);
void			sprite_sizer(int i, t_mlx_params *mlx);

int				anglizer(float vx1, float vy1, float vx2, float vy2);
int				angler(float alpha, float beta);

int				movement(t_mlx_params *mlx);
int				move_pl(int keycode, t_mlx_params *mlx, float speed);
int				rotate_pl(int keycode, t_mlx_params *mlx, float speed);
int				strafe_pl(int keycode, t_mlx_params *mlx, float speed);
int				check_coords(char dir, char side, t_mlx_params *mlx, float speed);
void			wall_dist_calc(char dir, t_mlx_params *mlx);
int				wall_check(float x, float y, t_mlx_params *mlx);
void			inverse_cam(char dir, t_mlx_params *mlx);

int				key_press(int keycode, t_mlx_params *mlx);
int				key_release(int keycode, t_mlx_params *mlx);

int				escape_key(int keycode);

int				get_colour(char *line, t_mlx_params *mlx);
char			*get_path(char *line, t_mlx_params *mlx);
int				get_map(char **grid, int maxlen, char *line);
void			dup_map(char **grid, char **dup);
void			get_resolution(t_map *map_data, char *line, t_mlx_params *mlx);

int				create_bitmap(t_mlx_params *mlx);

void			free_matrix(t_mlx_params *mlx, int mode);
void			mem_check(void *ptr, t_mlx_params *mlx, int ernum, int stage);
void			file_check(void *ptr, t_mlx_params *mlx, int j);
void			matrix_check(void *ptr, t_mlx_params *mlx, int j, int mode);
void			sp_check(void *ptr, t_mlx_params *mlx, int j);
void			error_handler(int ernum, t_mlx_params *mlx, int stage);
void			free_all(t_mlx_params *mlx, int stage);

int				rgbtoi(int t, int r, int g, int b);
int				trgbmod(int trgb, float factor);
void			shader(t_mlx_params *mlx);
float			dist_calc(float x, float y);
float			ft_dist(float x1, float y1, float x2, float y2);
int				anglizer(float vx1, float vy1, float vx2, float vy2);
float			rad_deg(float rad);
float			deg_rad(float deg);

#endif
