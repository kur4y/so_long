# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanota <tanota@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:33:56 by tanota            #+#    #+#              #
#    Updated: 2023/11/07 12:36:31 by tanota           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=			srcs/check_map.c				\
								srcs/create_game.c				\
								srcs/help.c srcs/help2.c 		\
								srcs/init.c						\
								srcs/main.c						\
								srcs/create_map.c				\
								srcs/onechar.c

NAME				=			so_long

CC					=			cc

CFLAGS				=			-Wall -Wextra -Werror

OBJS				=			$(SRCS:.c=.o)

LFLAGS				=			libmlx.a libmlx_Linux.a -lX11 -lXext

all					:			$(NAME)

$(NAME)				:			$(OBJS)
								make -C libft/ && mv libft/libft.a .
								make -C minilibx-linux/ && mv minilibx-linux/libmlx.a . && mv minilibx-linux/libmlx_Linux.a .
								$(CC) -o $(NAME) $(OBJS) $(LFLAGS) libft.a
								@echo "===== so_long has been created ====="

clean				:
								make clean -C libft/
								make clean -C minilibx-linux/
								rm -rf $(OBJS)
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME) libft.a libmlx.a libmlx_Linux.a
								@echo "===== so_long has been deleted ====="

re					:			fclean all
								@echo "===== so_long has been deleted and re-created ====="

.PHONY				:			all bonus clean fclean re
								@echo "===== so_long created, deleted and re-created done ====="
