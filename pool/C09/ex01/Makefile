# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mest <oel-mest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 11:55:07 by oel-mest          #+#    #+#              #
#    Updated: 2024/09/17 12:32:12 by oel-mest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs
SRC_FILES = $(SRC_DIR)/ft_putchar.c \
			$(SRC_DIR)/ft_swap.c \
			$(SRC_DIR)/ft_putstr.c \
			$(SRC_DIR)/ft_strlen.c \
			$(SRC_DIR)/ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
H_DIR = includes
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIB_NAME = libft.a

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	$(AR) $@ $(OBJ_FILES)

%.o: %.c
	$(CC) $(FLAGS) -I $(H_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
