# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 21:20:54 by oel-mest          #+#    #+#              #
#    Updated: 2024/12/22 20:20:43 by oel-mest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = cc
CFLAGS   = -Wall -Wextra -Werror
# ft_printf
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = libftprintf.a
FT_PRINTF_SRC = $(FT_PRINTF_DIR)/ft_printf.c \
				$(FT_PRINTF_DIR)/ft_printf_utils.c \
				$(FT_PRINTF_DIR)/ft_printf_utils_1.c

FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)
FT_HEADERS = $(FT_PRINTF_DIR)/ft_printf.h
# subject
UTILS_SRC = utils_1.c utils_2.c utils_3.c
UTILS_OBJ = $(UTILS_SRC:.c=.o)

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_BIN = server

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT_BIN = client

HEADER_FILE = minitalk.h
# Default target
all: $(SERVER_BIN) $(CLIENT_BIN)

# Build ft_printf
$(FT_PRINTF_LIB): $(FT_PRINTF_OBJ)
	ar rcs $(FT_PRINTF_LIB) $(FT_PRINTF_OBJ)

# Build server
$(SERVER_BIN): $(SERVER_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER_BIN) $(SERVER_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)

# Build client
$(CLIENT_BIN): $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT_BIN) $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)

# Object files
%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_DIR)/%.o : $(FT_PRINTF_DIR)/%.c $(FT_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
# Clean targets
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_OBJ)

fclean: clean
	$(RM) $(SERVER_BIN) $(CLIENT_BIN) $(FT_PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re
