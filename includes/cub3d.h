/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 00:40:10 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/11 21:55:19 by sachouam         ###   ########.fr       */
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

typedef struct	s_data
{
	unsigned int	reswid;
	unsigned int	reshei;
	unsigned int	sizex;
	unsigned int	sizey;
	unsigned int	floor1;
	unsigned int	floor2;
	unsigned int	floor3;
	unsigned int	ceil1;
	unsigned int	ceil2;
	unsigned int	ceil3;
	char		**map;
	int		fd;
	char		posplay;
}			t_data;

typedef struct	s_texture
{
	void		*pict;
	int		width;
	int		height;
}			t_texture;

typedef	struct	s_elem
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_texture	sprite;
}			t_elem;

typedef struct	s_vect
{
	double		posy;
	double		posx;
	int		mapx;
	int		mapy;
	int		movx;
	int		movy;
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
	int		hit;
	int		side;

	int		pixbeg;
	int		pixend;

}			t_vect;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*windo;
	void		*img;
	int		*addr;
	int		bpp;
	int		colhei;
	int		endian;
	int		color;
	int		ll;
	int		pixbeg;
	int		pixend;
}			t_mlx;

typedef struct	s_all
{
	t_data		data;
	t_vect		vect;
	t_mlx		disp;
	t_elem		text;
}			t_all;

void			ft_init_structs(t_all *all);
char			**ft_parsing_file_cub(t_all *all, char *file);
int			ft_parse_tab_pos_play(t_all *all);
void			ft_set_dir_and_angle(t_all *all);
int			ft_window_and_image(t_all *all);
void			ft_free_all(t_all *all);
int			ft_abort_mission(t_all *all);
void			ft_raycasting(t_all *all);
void			ft_check_raycol_value(t_all *all);
int			ft_key_management(int key, t_all *all);
void			ft_move_forward(t_all *all);
void			ft_move_to_the_left(t_all *all);
void			ft_move_backwards(t_all *all);
void			ft_move_to_the_right(t_all *all);
void			ft_draw_ceil_and_floor(t_all *all);
int			ft_get_color(unsigned int r,
			unsigned int g, unsigned int b);
void			ft_draw_pixel(t_all *all, int y, int x);
void			ft_hooks_and_loops(t_all *all);
double			ft_degree_to_radian(int degree);
int			ft_radian_to_degree(double radian);
double			ft_pow(double nb, int power);
void			ft_recreate_image(t_all *all);
void			ft_raycol_north_east(t_all *all,
			double modx, double mody);
void			ft_raycol_north_west(t_all *all,
			double modx, double mody);
void			ft_raycol_south_west(t_all *all,
			double modx, double mody);
void			ft_raycol_south_east(t_all *all,
			double modx, double mody);
void			ft_check_raycol_dir_part_two(t_all *all,
			double modx, double mody);
double			ft_set_hyph(t_all *all, double mody);
double			ft_set_hypv(t_all *all, double modx);
double			ft_set_cos(t_all *all);
double			ft_set_sin(t_all *all);

#endif
