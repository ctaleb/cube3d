/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:46:12 by ctaleb            #+#    #+#             */
/*   Updated: 2021/03/04 11:06:57 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	 s_map {
	char		**file;
	char		**grid;
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
	int			sprite_nb;
	int			floor_c;
	int			ceiling_c;
}				t_map;

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
	float		e_x;
	float		e_y;
	float		dist_x;
	float		dist_y;
	int			side;
	int			u_wall;
	int			l_wall;
}				t_ray;

typedef struct	s_fov {
	int			fov;
	float		cam_x;
	float		cam_y;
	float		*dist;
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
	float		x;
	float		y;
	float		dist;
	float		r_x;
	float		r_y;
}				t_sprites;

typedef struct	s_mlx_parmas {
	void		*ptr;
	void		*win;
	t_image		*img;
	t_map		*map;
	t_texture	*n_txt;
	t_texture	*s_txt;
	t_texture	*e_txt;
	t_texture	*w_txt;
	t_texture	*sp_txt;
	t_player	*pl;
	t_ray		*r;
	t_fov		*f;
	t_sprites	**sp;
}				t_mlx_params;

t_map			*map_open(char *path);

int				file_len(char *path);
int				is_map(char *line);
int				analyne(t_map *map_data, char *line);

int				data_check(t_map *map_data);
void			start_check(t_map *map_data);
void			map_check(int x, int y, t_map *map_data);

void			map_data_init(t_map *map_data, char *path);
void			grid_init(t_map *map_data);
void			map_init(t_map *map_data);
t_image			*img_init(t_mlx_params *mlx);
t_mlx_params	*mlx_data_init(char *path);
t_player		*pl_init(t_map *map_data);
void			sprite_init(t_mlx_params *mlx);
void			fov_init(t_mlx_params *mlx);
void			ray_init(t_mlx_params *mlx);
void			texture_init(t_mlx_params *mlx);

int				frame_gen(t_mlx_params *mlx);
void			my_mlx_pixel_put(t_mlx_params *mlx, int x, int y, int color);
void			print_minimap(t_mlx_params *mlx);
void			put_map(int x, int y, t_mlx_params *mlx);
void			put_player(t_mlx_params *mlx);
void			rem_player(t_mlx_params *mlx);
void			put_camera(t_mlx_params *mlx);
void			rem_camera(t_mlx_params *mlx);
void			put_fov(t_mlx_params *mlx);

void			ray_cannon(float fish, t_mlx_params *mlx);
void			sprite_check(t_mlx_params *mlx);
void			sprite_dist(t_mlx_params *mlx);
void			sprites_sort(t_mlx_params *mlx);

int				movement(int keycode, t_mlx_params *mlx);
int				move_pl(int keycode, t_mlx_params *mlx);
int				rotate_pl(int keycode, t_mlx_params *mlx);
int				check_coords(char dir, t_mlx_params *mlx);
void			wall_dist_calc(char dir, t_mlx_params *mlx);
int				wall_check(float x, float y, t_mlx_params *mlx);
void			inverse_cam(char dir, t_mlx_params *mlx);

int				escape_key(int keycode);

int				get_colour(char *line);
char			*get_path(char *line);
int				get_map(char **grid, int maxlen, char *line);
void			dup_map(char **grid, char **dup);
void			get_resolution(t_map *map_data, char *line);

void			error_handler(int ernum);

int				rgbtoi(int t, int r, int g, int b);

#endif
