# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snedir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/07 01:53:42 by snedir            #+#    #+#              #
#    Updated: 2017/11/07 05:47:34 by snedir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = snedir.filler

SRCS = parser.c \
	   misc.c \
	   trash_norme.c \
	   algos.c \
	   filler.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C gnl/libft
	@gcc $(FLAGS) $(OBJS) gnl/libft/libft.a -o $(NAME)

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
