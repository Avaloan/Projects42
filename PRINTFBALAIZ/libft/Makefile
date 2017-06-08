#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 15:41:11 by fdidelot          #+#    #+#              #
#    Updated: 2017/06/08 02:44:56 by snedir           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAG =	-Wall -Wextra -Werror

NAME =	libft.a

PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./

SRCC =	ft_strwdup.c \
		ft_atoi_u.c \
		ft_strjoin_size_free.c \
		ft_itoa_base_maj_signed.c \
		ft_itoa_base_maj.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strcpy.c	\
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c	\
		ft_putnbr_fd.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c	\
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strlcat.c \
		ft_strsub.c \
		ft_strsub_free.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strrev.c \
		ft_recursive_factorial.c \
		ft_sqrt.c \
		ft_range.c \
		ft_foreach.c \
		ft_count_occur.c \
		ft_count_if.c \
		ft_strjoin_free.c \
		ft_itoa_base.c \

SRCO =	$(SRCC:.c=.o)

SRC = $(addprefix $(PATH_SRC), $(SRCC))
OBJ = $(addprefix $(PATH_OBJ), $(SRCO))

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
		gcc $(FLAG) -I $(PATH_INC) -c $<

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all
