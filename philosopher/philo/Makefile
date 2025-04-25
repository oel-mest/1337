# Colors
RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RESET  = \033[0m

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

# Files
SRC_FILES = forks_1.c forks_2.c getters_1.c getters_2.c helpers.c \
            init.c main.c monitors.c parsing.c routine.c setters.c \
            threads.c timestamp.c

OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = philo.h
NAME = philo

# Targets
all: $(NAME)
	@echo "$(GREEN)✅ Build complete!$(RESET)"

$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)🔨 Linking $(TARGET)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)✅ Linking Done!$(RESET)"

%.o: %.c $(HEADER)
	@echo "$(BLUE)📄 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"

bonus: phile
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"

re: fclean all

.PHONY: all clean fclean re
