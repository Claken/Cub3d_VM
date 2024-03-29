/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 00:40:10 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/29 03:50:37 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../cub3d_mlx/mlx.h"
# include "get_next_line.h"
# include "../cub3d_libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define KP			2
# define KR			3
# define DN			33
# define NTXT		5

# define UP			119
# define LEFT		97
# define DOWN		115
# define RIGHT		100
# define ESC		65307
# define LARROW		65361
# define RARROW		65363
# define FOV		60
# define CASE		1

# define PI			3.141592653589793
# define FULL		6.28319

typedef struct		s_data
{
	unsigned int	reswid;
	unsigned int	reshei;
	unsigned int	rescount;
	unsigned int	sizex;
	unsigned int	sizey;
	int				floor1;
	int				floor2;
	int				floor3;
	unsigned int	flocount;
	int				ceil1;
	int				ceil2;
	int				ceil3;
	unsigned int	ceicount;
	char			**map;
	int				fd;
	char			posplay;
	unsigned int	uncorrectid;
	unsigned int	playercount;
}					t_data;

typedef struct		s_images
{
	void			*pict;
	int				width;
	int				height;
	char			*path;
	int				*addr;
	int				bpp;
	int				endian;
	int				linelen;
	unsigned int	imgcount;
}					t_images;

typedef struct		s_elem
{
	t_images		north;
	t_images		south;
	t_images		west;
	t_images		east;
	t_images		sprite;
}					t_elem;

typedef struct		s_sprite
{
	int				j;
	int				begx;
	int				centerx;
	int				endx;
	double			ix;
	double			iy;
	double			x;
	double			y;
	double			distance;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_angle
{
	double			dir;
	double			fov;
	double			apr;
	double			raycol;
	double			teta;
}					t_angle;

typedef struct		s_calcul
{
	double			distscreen;
	double			distwall;
	double			nofisheye;
	double			modxl;
	double			modyu;
}					t_calcul;

typedef struct		s_vect
{
	double			posy;
	double			posx;
	double			fhx;
	double			fhy;
	double			fvx;
	double			fvy;
	double			hx;
	double			hy;
	double			vx;
	double			vy;
	int				side;
}					t_vect;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*windo;
	void			*img;
	int				*addr;
	int				bpp;
	int				endian;
	int				linelen;
	int				colhei;
	int				color;
	int				pixbeg;
	int				pixend;
}					t_mlx;

typedef struct		s_keys
{
	int				up;
	int				down;
	int				right;
	int				left;
	int				r_arr;
	int				l_arr;
}					t_keys;

typedef struct		s_bmp
{
	int				save;
	unsigned char	*buffer;
	size_t			i;
	size_t			size;
}					t_bmp;

typedef struct		s_all
{
	t_data			data;
	t_vect			vect;
	t_angle			angle;
	t_calcul		calcul;
	t_mlx			disp;
	t_elem			image;
	t_keys			key;
	t_bmp			bmp;
	t_sprite		*sprites;
	double			*distwalls;
}					t_all;

int					ft_save_bmp_image(t_all *all, char *filename);

void				ft_free_all(t_all *all);
void				ft_destroy_images(t_all *all);
void				ft_abort_mission(t_all *all);

void				ft_init_structs(t_all *all);

int					ft_loop_hook(t_all *all);
int					ft_window_and_image(t_all *all);
void				ft_hooks_and_loops(t_all *all);
void				ft_create_image(t_all *all);

void				ft_error_message(char *sentence);
int					ft_error_so_exit(char *sentence, t_all *all);

int					ft_good_bye(t_all *all);
void				ft_move_camera_right(t_all *all);
void				ft_move_camera_left(t_all *all);

int					ft_key_pressed(int key, t_all *all);
int					ft_key_released(int key, t_all *all);
void				ft_key_management(t_all *all);

void				ft_move_forward(t_all *all);
void				ft_move_to_the_left(t_all *all);
void				ft_move_backwards(t_all *all);
void				ft_move_to_the_right(t_all *all);

double				ft_degree_to_radian(int degree);
int					ft_radian_to_degree(double radian);
int					ft_get_color(unsigned int r,
					unsigned int g, unsigned int b);
void				ft_draw_pixel(t_all *all, int y, int x);
void				ft_free_tab(char **tab);

int					ft_check_raycol_direction(t_all *all);

void				ft_draw_ceil_and_floor(t_all *all);

int					ft_add_sprite_back(t_sprite **spr, double sx, double sy);
void				ft_sort_sprites(t_sprite **spr);
void				ft_sprclear(t_sprite **spr);

void				ft_check_sprites_on_the_map(t_all *all);
void				ft_sprite_calculations(t_all *all, t_sprite **spr);
void				ft_sprite_mapping(t_all *all, t_sprite *spr);

void				ft_sprites_management(t_all *all);

void				ft_textures_management(t_all *all, int index);

double				ft_set_hyph(t_all *all);
double				ft_set_hypv(t_all *all);

void				ft_raycol_north_east(t_all *all);
void				ft_raycol_north_west(t_all *all);
void				ft_raycol_south_west(t_all *all);
void				ft_raycol_south_east(t_all *all);
void				ft_raycol_special_cases(t_all *all, int direction);

int					ft_check_arguments(char *arg1, char *arg2, t_all *all);
void				ft_check_cub_data(t_all *all);
void				ft_check_walls(t_all *all);

char				**ft_parsing_file_cub(t_all *all, char *file);

int					ft_parse_tab_pos_play(t_all *all);
void				ft_set_dir_and_angle(t_all *all);

int					ft_parsing_rfc(char *line, t_all *all);

void				ft_parsing_image(char *line, t_all *all);

void				ft_raycasting(t_all *all);
void				ft_check_for_walls(t_all *all);
void				ft_distance_calculation(t_all *all);
void				ft_distance_with_no_fisheye(t_all *all);

#endif
