CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBCMD = -lmlx -framework OpenGL -framework AppKit

SRC_FILES = utils_1.c utils_2.c handlers.c helpers.c main.c tricorn.c color.c
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = fractol

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LIBCMD)

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re