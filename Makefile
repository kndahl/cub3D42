# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 21:08:31 by kdahl             #+#    #+#              #
#    Updated: 2020/10/03 19:51:39 by kdahl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = -lmlx -lm -framework OpenGL -framework AppKit

SRCS = 	gnl/get_next_line.c \
		engine/arg_parser.c engine/draw.c engine/get_colors.c \
		engine/keyboard.c engine/main.c engine/map_render.c \
		engine/mapandplayer_parser.c engine/path2.c \
		engine/print_error.c engine/rays.c engine/sprites.c \
		engine/arg_parser_2.c engine/cub3d_engine.c \
		engine/sprite_calc.c engine/bmp.c engine/mouse.c \
		engine/shooting.c engine/bonus_textures.c engine/notifications.c

OBJS = $(SRCS:.c = .o)


CC = gcc -Wall -Wextra -Werror ${SRCS}

all:	$(NAME)

$(NAME):	$(OBJS)
			@echo "\033[35m[MinilibX compilation...]"
			@$(MAKE) -C ./minilibx
			@echo "\033[33m[Libft compilation...]"
			@$(MAKE) -C ./libft
			@echo "\033[36m[Cub3D compilation...]"
			$(CC) -L minilibx -L libft -lft -Ilibft -Iminilibx $(MLX) -lz ./libft/libft.a -o $(NAME)
			cp minilibx/libmlx.dylib .
			@echo "\033[32m[Done !]"

clean:	
		$(MAKE) clean -C ./libft

fclean:	
		rm -rf $(NAME)
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./minilibx
		rm -rf libmlx.dylib
		rm -f cub3D.bmp

re:		fclean all

.PHONY:	all clean fclean re