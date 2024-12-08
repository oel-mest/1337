# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 17:53:00 by oel-mest          #+#    #+#              #
#    Updated: 2024/10/30 16:09:36 by oel-mest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

MAIN_OBJ = $(MAIN_FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = libft.a

HEADERS = libft.h

all: $(NAME)

$(NAME): $(MAIN_OBJ)
	$(AR) $@ $(MAIN_OBJ)

bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(BONUS_OBJ) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
