NAME		= Cub3D

NAME_LIBFT	= cub3d_libft/libft.a

NAME_MLX	= cub3d_mlx/libmlx.a

INCLUDES	= cub3d_includes

MLXH		= cub3d_mlx/mlx.h

LIBFT		= cub3d_libft

MLX		= cub3d_mlx

CC		= clang

MFLAGS		= -lX11 -lXext -lm -lbsd -L $(MLX) -lmlx

CFLAGS		= -Wall -Wextra -Werror #-g

SRC 		= cub3d_gnl/get_next_line.c \
		cub3d_gnl/get_next_line_utils.c \
		cub3d_srcs/bmp_save/save_bmp_image.c \
		cub3d_srcs/clear_cub3d/clear_cub3d.c \
		cub3d_srcs/cub3d.c \
		cub3d_srcs/display/c3d_display.c \
		cub3d_srcs/errors_handling/errors_handling.c \
		cub3d_srcs/event_handling/exit_and_cam.c \
		cub3d_srcs/event_handling/keys.c \
		cub3d_srcs/event_handling/move.c \
		cub3d_srcs/functions/c3d_utils.c \
		cub3d_srcs/functions/check_raycol_direction.c \
		cub3d_srcs/functions/draw_floor_and_ceiling.c \
		cub3d_srcs/functions/functions_for_map_parsing.c \
		cub3d_srcs/maths_files/find_hypothenus.c \
		cub3d_srcs/maths_files/set_xs_and_ys.c \
		cub3d_srcs/parsing_map/check_data/check_data.c \
		cub3d_srcs/parsing_map/check_data/check_walls.c \
		cub3d_srcs/parsing_map/get_data/get_file_cub_and_map.c \
		cub3d_srcs/parsing_map/get_data/get_player_and_direction.c \
		cub3d_srcs/parsing_map/get_data/get_res_flo_and_ceil.c \
		cub3d_srcs/parsing_map/get_data/get_textures_and_sprite.c \
		cub3d_srcs/raycasting/check_for_walls.c \
		cub3d_srcs/raycasting/distance.c \
		cub3d_srcs/raycasting/ray_casting.c \
		cub3d_srcs/images_handling/functions_list_sprites.c \
		cub3d_srcs/images_handling/sprites_data_calcul_mapping.c \
		cub3d_srcs/images_handling/sprites_management.c \
		cub3d_srcs/images_handling/textures_management.c \

OBJ		= ${SRC:.c=.o}

.c.o:
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(MLXH) $(NAME_MLX) $(SRC) $(NAME_LIBFT) -o $(NAME) $(MFLAGS)
		#-g3 -fsanitize=address

all:            $(NAME)

makefirst:
		make bonus -C $(LIBFT)
		make -C $(MLX)

$(NAME):        makefirst $(OBJ)

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)
		make clean -C $(MLX)

fclean:		clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)

re:		fclean all

run:
		@make re && make clean
		@./Cub3D cub3d_maps/mapex.cub
run2:
		@make re && make clean
		@./Cub3D cub3d_maps/squaremap.cub
run3:
		@make re && make clean
		@./Cub3D cub3d_maps/rectmap.cub

testpars:
		$(CC) -I $(INCLUDES) -I $(MLXH) $(NAME_MLX) maincub.c cub3d_gnl/get_next_line.c cub3d_gnl/get_next_line_utils.c $(NAME_LIBFT) $(MFLAGS) -o pars
		./pars cub3d_maps/mapex.cub

testgraph:
		$(CC) -I $(INCLUDES) -I $(MLXH) $(NAME_MLX) maingraph.c $(MFLAGS) -o graph
		./graph

testlist:
		clang -I cub3d_includes mainlst.c -o mainlst -lm
		./mainlst

.PHONY: all clean fclean re
