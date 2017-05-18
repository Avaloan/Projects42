#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 15:41:11 by fdidelot          #+#    #+#              #
#    Updated: 2017/04/05 03:48:59 by fdidelot         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAG =	

NAME =	ft_printf

PATH_SRC = ./srcs/
PATH_OBJ = ./
PATH_INC = ./includes/

SRCC =	 ft_printf.c

SRCO =	$(SRCC:.c=.o)

SRC = $(addprefix $(PATH_SRC), $(SRCC))
OBJ = $(addprefix $(PATH_OBJ), $(SRCO))
HEAD = $(PATH_INC)ft_printf.h

all:	$(NAME)

$(NAME):
		gcc -c $(SRC) -I $(HEAD)
		gcc -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all $(NAME) $(PATH_OBJ)%.o clean fclean re