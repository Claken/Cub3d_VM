CC		= clang

CFLAGS		= -Wall -Wextra -Werror -g

MFLAGS		= -lX11 -lXext -lm -lbsd -lmlx

NAME		= Cub3D

NAME_LIBFT	= cub3d_libft/libft.a

NAME_MLX	= libmlx.a

INCLUDES	= includes

MLX		= /usr/local/include

LIBFT		= cub3d_libft

SRC 		= cub3d_gnl/get_next_line.c \
		cub3d_gnl/get_next_line_utils.c \
		cub3d_srcs/cub3d.c \
		cub3d_srcs/clear_cub3d.c \
		cub3d_srcs/check_raycol_direction.c \
		cub3d_srcs/errors_handling.c \
		cub3d_srcs/parsing_map_check_data_01.c \
		cub3d_srcs/parsing_map_check_data_02.c \
		cub3d_srcs/parsing_map_get_data_01.c \
		cub3d_srcs/parsing_map_get_data_02.c \
		cub3d_srcs/parsing_map_get_data_03.c \
		cub3d_srcs/parsing_map_get_data_04.c \
		cub3d_srcs/c3d_display_01.c \
		cub3d_srcs/ray_casting_01.c \
		cub3d_srcs/ray_casting_02.c \
		cub3d_srcs/ray_casting_03_floor_and_ceiling.c \
		cub3d_srcs/set_xs_and_ys.c \
		cub3d_srcs/find_hypothenus.c \
		cub3d_srcs/event_handling_01_exit_and_cam.c \
		cub3d_srcs/event_handling_02_keys.c \
		cub3d_srcs/event_handling_03_move.c \
		cub3d_srcs/c3d_utils_01.c \
		cub3d_srcs/functions_for_map_parsing.c \
		cub3d_srcs/save_bmp_image.c \
		debugging.c \

OBJ		= ${SRC:.c=.o}

.c.o:
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(MLX) $(NAME_MLX) $(SRC) $(NAME_LIBFT) -o $(NAME) $(MFLAGS)
		#-g3 -fsanitize=address

all:            $(NAME)

makefirst:
		make bonus -C $(LIBFT)
		cp /usr/local/lib/libmlx.a .

$(NAME):        makefirst $(OBJ)

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:		clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)
		rm -rf $(NAME_MLX)

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
		$(CC) -I $(INCLUDES) -I $(MLX) $(NAME_MLX) maincub.c cub3d_gnl/get_next_line.c cub3d_gnl/get_next_line_utils.c $(NAME_LIBFT) $(MFLAGS) -o pars
		./pars cub3d_maps/mapex.cub

testgraph:
		$(CC) -I $(INCLUDES) -I $(MLX) $(NAME_MLX) maingraph.c $(MFLAGS) -o graph
		./graph

.PHONY: all clean fclean re
