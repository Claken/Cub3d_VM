/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 00:40:10 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/06 12:02:18 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../cub3d_mlx/mlx.h"
# include "/usr/include/X11/X.h"
# include "get_next_line.h"
# include "../cub3d_libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

//<unistd.h>

# define KP		2
# define KR		3
# define DN		17
# define NTXT		5

# define UP		122
# define LEFT		113
# define DOWN		115
# define RIGHT		100
# define ESC		65307
# define LARROW		65361
# define RARROW		65363
# define FOV		60
# define CASE		1

# define PI		3.141592653589793
# define FULL		6.28319

typedef struct	s_data
{
	unsigned int	reswid;
	unsigned int	reshei;
	unsigned int	sizex;
	unsigned int	sizey;
	int		floor1;
	int		floor2;
	int		floor3;
	int		ceil1;
	int		ceil2;
	int		ceil3;
	char		**map;
	int		fd;
	char		posplay;
}			t_data;

typedef struct	s_images
{
	void		*pict;
	int		width;
	int		height;
	char		*path;
	int		*addr;
	int		bpp;
	int		endian;
	int		linelen;
}			t_images;

typedef struct	s_elem
{
	t_images	north;
	t_images	south;
	t_images	west;
	t_images	east;
	t_images	sprite;
}			t_elem;
/*
typedef struct	s_sprite
{
	double		x;
	double		y;
	int		side;
	double		sdist;
	double		colhei;
	double		pixbeg;
	double		pixend;
	int		xbeg; // debut colonne de x
	int		xend; // fin colonne de x
	double		*raycols;
	s_sprite	*next;
}			t_sprite;
*/
typedef struct s_sprite
{
	int		rayx;
	int		j;
	int		begx;
	int		endx;
	double		x;
	double		y;
	int		side;
	double		distwall;
	double		*raycols;
}			t_sprite;

typedef struct	s_vect
{
	double		posy;
	double		posx;
	double		dir;
	double		fov;
	double		apr;
	double		raycol;
	double		teta;

	double		fhx;
	double		fhy;

	double		fvx;
	double		fvy;

	double		hx;
	double		hy;

	double		vx;
	double		vy;

	double		distscreen;
	double		distwall;
	double		nofisheye;
	int		side;

	int		pixbeg;
	int		pixend;

	double		modxl;
	double		modyu;

	int		index;
}			t_vect;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*windo;
	void		*img;
	int		*addr;
	int		bpp;
	int		endian;
	int		linelen;
	int		colhei;
	int		color;
	int		pixbeg;
	int		pixend;
}			t_mlx;

typedef struct	s_keys
{
	int		up;
	int		down;
	int		right;
	int		left;
	int		r_arr;
	int		l_arr;
}			t_keys;

typedef struct	s_bmp
{
	int		save;
	unsigned char	*buffer;
	size_t		i;
	size_t		size;
}			t_bmp;

typedef struct	s_all
{
	t_data		data;
	t_vect		vect;
	t_mlx		disp;
	t_elem		image;
	t_keys		key;
	t_bmp		bmp;
	t_sprite	spr;
}			t_all;

void			ft_init_structs(t_all *all);
int			ft_check_arguments(char *arg1, char *arg2, t_all *all);
void			ft_check_cub_data(t_all *all);
char			*ft_replace_in_str(char *str, char a, char b);
void			*ft_realloc(void *ptr, size_t size);
char			*ft_reset_line_size(char *line, int size, int i);
int			ft_check_first_or_last(char *line);
int			ft_check_beginning_and_end(char *line);
void			ft_check_walls(t_all *all);
char			**ft_parsing_file_cub(t_all *all, char *file);
void			ft_parsing_image(char *line, t_all *all);
int			ft_parsing_rfc(char *line, t_all *all);
int			ft_parse_tab_pos_play(t_all *all);
void			ft_set_dir_and_angle(t_all *all);
int			ft_save_bmp_image(t_all *all, char *filename);
int			ft_window_and_image(t_all *all);
void			ft_free_all(t_all *all);
void			ft_destroy_images(t_all *all);
void			ft_free_tab(char **tab);
int			ft_error_so_exit(char *sentence, t_all *all);
void			ft_error_message(char *sentence);
void			ft_abort_mission(t_all *all);
int			ft_good_bye(t_all *all);
void			ft_raycasting(t_all *all);
void			ft_check_for_walls_and_sprites(t_all *all, int i);
void			ft_distance_calculation(t_all *all);
void			ft_distance_with_no_fisheye(t_all *all);
int			ft_check_raycol_direction(t_all *all);
int			ft_key_pressed(int key, t_all *all);
int			ft_key_released(int key, t_all *all);
void			ft_key_management(t_all *all);
void			ft_move_forward(t_all *all);
void			ft_move_to_the_left(t_all *all);
void			ft_move_backwards(t_all *all);
void			ft_move_to_the_right(t_all *all);
void			ft_move_camera_right(t_all *all);
void			ft_move_camera_left(t_all *all);
int			ft_loop_hook(t_all *all);
void			ft_draw_ceil_and_floor(t_all *all);
int			ft_get_color(unsigned int r,
			unsigned int g, unsigned int b);
void			ft_draw_pixel(t_all *all, int y, int x);
void			ft_hooks_and_loops(t_all *all);
double			ft_degree_to_radian(int degree);
void			ft_create_image(t_all *all);
void			ft_raycol_north_east(t_all *all);
void			ft_raycol_north_west(t_all *all);
void			ft_raycol_south_west(t_all *all);
void			ft_raycol_south_east(t_all *all);
void			ft_raycol_special_cases(t_all *all, int direction);
double			ft_set_hyph(t_all *all);
double			ft_set_hypv(t_all *all);

void			ft_textures_management(t_all *all, int index);

void			ft_get_sprite_data(t_all *all, int i, int side);
void			ft_sprite_calculations(t_all *all);
void			ft_sprite_mapping(t_all *all);

#endif
