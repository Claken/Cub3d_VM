NAME		= cub3D

NAME_LIBFT	= cub3d_libft/libft.a

NAME_MLX	= cub3d_mlx/libmlx.a

INCLUDES	= cub3d_includes

MLXH		= cub3d_mlx/mlx.h

LIBFT		= cub3d_libft

# := constante
# ?= var ecrite si elle existe pas
# -MMD -MP flags pour les dépendances

MLX		= cub3d_mlx

CC		= clang

MFLAGS		= -lX11 -lXext -lm -lbsd -L $(MLX) -lmlx

CFLAGS		= -Wall -Wextra -Werror -MMD -MP

SRC		= cub3d_gnl/get_next_line.c \
		cub3d_gnl/get_next_line_utils.c \
		cub3d_srcs/bmp_save/save_bmp_image.c \
		cub3d_srcs/clear_cub3d/clear_cub3d.c \
		cub3d_srcs/cub3d.c \
		cub3d_srcs/display/c3d_display.c \
		cub3d_srcs/errors_handling/errors_handling.c \
		cub3d_srcs/event_handling/move.c \
		cub3d_srcs/event_handling/keys.c \
		cub3d_srcs/event_handling/exit_and_cam.c \
		cub3d_srcs/functions/draw_floor_and_ceiling.c \
		cub3d_srcs/functions/check_raycol_direction.c \
		cub3d_srcs/functions/c3d_utils.c \
		cub3d_srcs/images_handling/sprites_management.c \
		cub3d_srcs/images_handling/functions_list_sprites.c \
		cub3d_srcs/images_handling/sprites_data_calcul_mapping.c \
		cub3d_srcs/images_handling/textures_management.c \
		cub3d_srcs/maths_files/set_xs_and_ys.c \
		cub3d_srcs/maths_files/find_hypothenus.c \
		cub3d_srcs/parsing_map/check_data/check_data.c \
		cub3d_srcs/parsing_map/check_data/check_arguments.c \
		cub3d_srcs/parsing_map/check_data/check_walls.c \
		cub3d_srcs/parsing_map/get_data/get_player_and_direction.c \
		cub3d_srcs/parsing_map/get_data/get_file_cub_and_map.c \
		cub3d_srcs/parsing_map/get_data/get_res_flo_and_ceil.c \
		cub3d_srcs/parsing_map/get_data/get_textures_and_sprite.c \
		cub3d_srcs/raycasting/check_for_walls.c \
		cub3d_srcs/raycasting/ray_casting.c \
		cub3d_srcs/raycasting/distance.c \

OBJ		= $(SRC:.c=.o)
# pour créer les fichiers .o

DEP		= $(SRC:.c=.d)
# pour créer les fichiers dépendances .d

all:		$(NAME)

%.o : %.c
		$(CC) -I$(INCLUDES) -o $@ -c $< $(CFLAGS)
# règle à appliquer à chaque fois qu'on génère de fichiers en .o
# la règle dépend de la présence des fichiers .c

$(NAME_LIBFT):
		make bonus -C $(LIBFT)

# Mettre un fichier en règle permet de vérifier que celui-ci est mis à jour pour compiler

$(NAME_MLX):
		make -C $(MLX)

$(NAME):	$(NAME_LIBFT) $(NAME_MLX) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(NAME_LIBFT) $(NAME_MLX) -o $(NAME) $(MFLAGS)

clean:
			rm -rf $(OBJ)
			rm -rf $(DEP)
			make clean -C $(LIBFT)
			make clean -C $(MLX)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all

-include $(DEP)
# pour inclure les fichier .d dans la compilation

run:
		@make re && make clean
		@./cub3D cub3d_maps/mapex.cub
run2:
		@make re && make clean
		@./cub3D cub3d_maps/squaremap.cub
run3:
		@make re && make clean
		@./cub3D cub3d_maps/rectmap.cub

.PHONY: all clean fclean re run run2 run3