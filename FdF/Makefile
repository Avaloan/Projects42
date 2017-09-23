# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/09/22 00:26:13 by snedir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	misc.c \
		parsing.c \
		test_image.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C gnl/libft
	@gcc $(FLAGS) $(OBJS) gnl/libft/libft.a minilibx_macos/libmlx.a -o $(NAME) \
		-L. -framework OpenGL -framework AppKit

%.o: $(SRCPATH)%.c
	@gcc $(FLAGS) -c $< -I includes/

.PHONY: all clean fclean re

clean:
	@make -C gnl/libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C gnl/libft fclean
	@rm -rf gnl/libft/libft.a $(NAME)

re: fclean all
