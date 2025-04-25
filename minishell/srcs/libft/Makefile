# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

# File and directories
NAME = libft.a
SRCS = ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_memmove.c ft_strchr.c ft_strlen.c ft_strrchr.c \
       ft_tolower.c ft_toupper.c ft_atoi.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_memmove.c \
       ft_strnstr.c ft_strlcpy.c ft_isalpha.c ft_calloc.c ft_strdup.c \
       ft_strlcat.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
       ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

# Color definitions for output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

# Default target
all: ${NAME}

# Rule to create the library
${NAME}: ${OBJS}
	@echo "$(YELLOW)[LIBFT]$(RESET) Archiving $(NAME)..."
	@${AR} rcs ${NAME} ${OBJS}
	@echo "$(GREEN)[LIBFT]$(RESET) $(NAME) built successfully."

# Rule to compile object files
%.o: %.c libft.h
	@echo "$(YELLOW)[OBJ]$(RESET) Compiling $@..."
	@${CC} ${CFLAGS} -o $@ -c $<
	
# Clean rule
clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing libft object files..."
	@rm -rf ${OBJS}

# Full clean rule (clean + remove the library)
fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removing $(NAME)..."
	@rm -rf ${NAME}

# Rebuild rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re
