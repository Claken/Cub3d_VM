CC		= clang

CFLAGS		= -Wall -Wextra -Werror

MFLAGS		= -lX11 -lXext -lm -lbsd -lmlx 

NAME		= Cub3D

NAME_LIBFT	= cub3d_libft/libft.a

NAME_MLX	= libmlx.a

INCLUDES	= includes

MLX 		= /usr/local/include

LIBFT		= cub3d_libft

SRC 		= cub3d_gnl/get_next_line.c \
		cub3d_gnl/get_next_line_utils.c \
		cub3d.c \
		parsing_map_data_01.c \
		parsing_map_data_02.c \
		parsing_map_02.c \
		c3d_display_01.c \
		ray_casting_01.c \
		ray_casting_02.c \
		ray_casting_03_floor_and_ceiling.c \
		set_xs_and_ys.c \
		find_hypothenus.c \
		event_handling_01_exit_and_cam.c \
		event_handling_02_keys.c \
		event_handling_03_move.c \
		c3d_utils_01.c \

OBJ		= ${SRC:.c=.o}

.c.o:
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(MLX) $(NAME_MLX) $(SRC) $(NAME_LIBFT) -o $(NAME) $(MFLAGS) #-g3 -fsanitize=address

all:            $(NAME)

makefirst:
		make all -C $(LIBFT)
		cp /usr/local/lib/libmlx.a .

$(NAME):        makefirst $(OBJ)

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:		clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)
		rm -rf $(NAME_MLX)

re: 		fclean all

run:
		@make re && make clean
		@./Cub3D mapex.cub
run2:
		@make re && make clean
		@./Cub3D squaremap.cub
testmlx:
			gcc -I cub3d_mlx -g -L cub3d_mlx -l mlx -framework OpenGL -framework AppKit maingraph.c
			./a.out
testpars:
			gcc -I $(MLX) -I $(PRTF) -g -L $(MLX) -l mlx -framework OpenGL -framework AppKit maincub.c cub3d_gnl/get_next_line.c cub3d_gnl/get_next_line_utils.c cub3d_libft/*.c cub3d_libft/ft_printf/*.c
			./a.out mapex.cub

.PHONY: all clean fclean re
