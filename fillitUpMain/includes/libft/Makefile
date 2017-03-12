NAME = libft.a

SRCS = ft_atoi.c ft_memdel.c ft_strequ.c \
	ft_bzero.c ft_memmove.c ft_striter.c \
	ft_count_if.c ft_memset.c ft_striteri.c \
	ft_foreach.c ft_putchar.c ft_strjoin.c \
	ft_isalnum.c ft_putchar_fd.c ft_strlcat.c \
	ft_isalpha.c ft_putendl.c ft_strlen.c \
	ft_isascii.c ft_putendl_fd.c ft_strmap.c \
	ft_isdigit.c ft_putnbr.c ft_strmapi.c \
	ft_isprint.c ft_putnbr_fd.c ft_strncat.c \
	ft_itoa.c ft_putstr.c ft_strncmp.c \
	ft_lstadd.c ft_putstr_fd.c ft_strncpy.c \
	ft_lstdel.c ft_range.c ft_strnequ.c \
	ft_lstdelone.c ft_recursive_factorial.c ft_strnew.c \
	ft_lstiter.c ft_sqrt.c ft_strnstr.c \
	ft_lstmap.c ft_strcat.c ft_strrchr.c \
	ft_lstnew.c ft_strchr.c ft_strsplit.c \
	ft_memalloc.c ft_strclr.c ft_strstr.c \
	ft_memccpy.c ft_strcmp.c ft_strsub.c \
	ft_memchr.c ft_strcpy.c ft_strtrim.c \
	ft_memcmp.c ft_strdel.c ft_tolower.c \
	ft_memcpy.c ft_strdup.c ft_toupper.c \

OBJ = ft_atoi.o ft_memdel.o ft_strequ.o \
	ft_bzero.o ft_memmove.o ft_striter.o \
	ft_count_if.o ft_memset.o ft_striteri.o \
	ft_foreach.o ft_putchar.o ft_strjoin.o \
	ft_isalnum.o ft_putchar_fd.o ft_strlcat.o \
	ft_isalpha.o ft_putendl.o ft_strlen.o \
	ft_isascii.o ft_putendl_fd.o ft_strmap.o \
	ft_isdigit.o ft_putnbr.o ft_strmapi.o \
	ft_isprint.o ft_putnbr_fd.o ft_strncat.o \
	ft_itoa.o ft_putstr.o ft_strncmp.o \
	ft_lstadd.o ft_putstr_fd.o ft_strncpy.o \
	ft_lstdel.o ft_range.o ft_strnequ.o \
	ft_lstdelone.o ft_recursive_factorial.o ft_strnew.o \
	ft_lstiter.o ft_sqrt.o ft_strnstr.o \
	ft_lstmap.o ft_strcat.o ft_strrchr.o \
	ft_lstnew.o ft_strchr.o ft_strsplit.o \
	ft_memalloc.o ft_strclr.o ft_strstr.o \
	ft_memccpy.o ft_strcmp.o ft_strsub.o \
	ft_memchr.o ft_strcpy.o ft_strtrim.o \
	ft_memcmp.o ft_strdel.o ft_tolower.o \
	ft_memcpy.o ft_strdup.o ft_toupper.o \

all:$(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar rc $(NAME) $(OBJ)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
