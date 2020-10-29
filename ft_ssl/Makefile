.PHONY: all clean fclean re
.SILENT:

NAME = md5
DEBUG = md5Debug

FILE = main.c

INC = -I libft
SRC = $(FILE:%=%)
OBJ = $(FILE:%.c=objs/%.o)
CFLAGS = -Wall -Werror -Wextra  -fsanitize=address,undefined #-g3 -pedantic -Weverything
CC = clang $(CFLAGS) $(INC)
CCD = clang -DDEBUG $(INC)
RM = rm -rf

all: $(NAME)
debug: $(DEBUG)

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ)

$(DEBUG) : $(OBJ)
	clang -D DEBUG src/*.c -o md5Debug

objs/%.o: src/%.c
	mkdir -p objs
	$(CC) $(INC) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	rm -rf objs

fclean: clean
	$(RM) $(NAME)

fcleanDe: clean
	$(RM) $(DEBUG)

re: fclean
	$(MAKE)
