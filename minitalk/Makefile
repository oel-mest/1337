# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 21:20:54 by oel-mest          #+#    #+#              #
#    Updated: 2024/12/09 21:20:54 by oel-mest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = cc
CFLAGS   = -Wall -Wextra -Werror
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

UTILS_SRC = utils.c utils_1.c utils_2.c utils_3.c
UTILS_OBJ = $(UTILS_SRC:.c=.o)

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_BIN = server

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT_BIN = client

HEADER_FILE = minitalk.h
# Default target
all: $(FT_PRINTF_LIB) $(SERVER_BIN) $(CLIENT_BIN)

# Build ft_printf
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Build server
$(SERVER_BIN): $(SERVER_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER_BIN) $(SERVER_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)

# Build client
$(CLIENT_BIN): $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT_BIN) $(CLIENT_OBJ) $(UTILS_OBJ) $(FT_PRINTF_LIB)

# Object files
%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean targets
clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(RM) $(SERVER_BIN) $(CLIENT_BIN)

re: fclean all

.PHONY: all clean fclean re
