# Color variables for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m
CYAN = \033[0;36m

# Brew and Readline 
USERNAME := $(USER)
BREW_DIR := /goinfre/$(USERNAME)/homebrew
BREW_BIN := $(BREW_DIR)/bin/brew
READLINE_PREFIX := $(BREW_DIR)/opt/readline

# Compiler and flags
CC = cc -Wall -Wextra -Werror -MMD -MP
INCLUDES = -Iincludes -I$(READLINE_PREFIX)/include
LDFLAGS = -L$(READLINE_PREFIX)/lib -lreadline
LIBFTT = -L $(SRCS_DIR)/libft -lft

# Directories
SRCS_DIR = srcs
OBJS_DIR = objs
LIBFT = $(SRCS_DIR)/libft/libft.a

# Source files
SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/cleaning/clean_1.c \
       $(SRCS_DIR)/cleaning/clean_2.c \
       $(SRCS_DIR)/env/expander.c \
       $(SRCS_DIR)/env/expander_utils.c \
       $(SRCS_DIR)/env/expander2.c \
       $(SRCS_DIR)/env/parse_env.c \
       $(SRCS_DIR)/env/toberemoved.c \
       $(SRCS_DIR)/parsing/command_utils.c \
       $(SRCS_DIR)/parsing/command.c \
       $(SRCS_DIR)/parsing/helpers.c \
       $(SRCS_DIR)/parsing/logical.c \
       $(SRCS_DIR)/parsing/pipe.c \
       $(SRCS_DIR)/parsing/subshell_utils.c \
       $(SRCS_DIR)/parsing/subshell.c \
       $(SRCS_DIR)/parsing/utils.c \
       $(SRCS_DIR)/tokenizer/helpers.c \
       $(SRCS_DIR)/tokenizer/quotes.c \
       $(SRCS_DIR)/tokenizer/special_tokens.c \
       $(SRCS_DIR)/tokenizer/tokenize.c \
       $(SRCS_DIR)/tokenizer/utils.c \
       $(SRCS_DIR)/tokenizer/words.c \
       $(SRCS_DIR)/execution/subshell/subshell.c \
       $(SRCS_DIR)/execution/utils/executing_utils.c \
       $(SRCS_DIR)/execution/redirections/output.c \
       $(SRCS_DIR)/execution/redirections/input.c \
       $(SRCS_DIR)/execution/redirections/ambiguous.c \
       $(SRCS_DIR)/execution/redirections/ambuguous_utils.c \
       $(SRCS_DIR)/execution/exec_command/command.c \
       $(SRCS_DIR)/execution/exec_command/child_execution.c \
       $(SRCS_DIR)/execution/exec_command/context_management.c \
       $(SRCS_DIR)/execution/utils/error_utils.c \
       $(SRCS_DIR)/execution/utils/heredoc.c \
       $(SRCS_DIR)/execution/utils/heredoc_utils.c \
       $(SRCS_DIR)/execution/utils/misc_utils.c \
       $(SRCS_DIR)/execution/utils/misc2.c \
       $(SRCS_DIR)/execution/utils/quotes_utils.c \
       $(SRCS_DIR)/execution/utils/string_helpers.c \
       $(SRCS_DIR)/execution/builtins/core/cd.c \
       $(SRCS_DIR)/execution/builtins/core/echo.c \
       $(SRCS_DIR)/execution/builtins/core/env.c \
       $(SRCS_DIR)/execution/builtins/core/exit.c \
       $(SRCS_DIR)/execution/builtins/core/export.c \
       $(SRCS_DIR)/execution/builtins/core/pwd.c \
       $(SRCS_DIR)/execution/builtins/core/unset.c \
       $(SRCS_DIR)/execution/builtins/builtin_manager.c \
       $(SRCS_DIR)/execution/builtins/builtin_utils.c \
       $(SRCS_DIR)/execution/builtins/builtin_utils2.c \
       $(SRCS_DIR)/execution/wildcards/wildcard.c \
       $(SRCS_DIR)/execution/wildcards/wildcard_utils.c \
       $(SRCS_DIR)/execution/wildcards/wildcard_utils2.c \
       $(SRCS_DIR)/execution/pipes/pipe.c \
       $(SRCS_DIR)/execution/ast/execute_ast.c \
       $(SRCS_DIR)/execution/ast/execute_ast_utils.c \
       $(SRCS_DIR)/get_next_line/get_next_line.c \
       $(SRCS_DIR)/get_next_line/get_next_line_utils.c
# Object files
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Executable name
NAME = minishell

# Default target
all: $(LIBFT) $(NAME)

readline:
	@echo "📦 Setting up Homebrew in $(BREW_DIR)"
	@if [ ! -d "$(BREW_DIR)" ]; then \
		git clone https://github.com/Homebrew/brew $(BREW_DIR); \
	fi
	@echo "🍺 Installing readline..."
	@eval "$$($(BREW_BIN) shellenv)" && \
		brew update && \
		brew install readline
	@echo "✅ readline installed at $(READLINE_PREFIX)"

$(LIBFT):
	@echo "$(CYAN)[LIBFT]$(RESET) Building libft..."
	@make -C $(SRCS_DIR)/libft/

# Rule to compile the executable
$(NAME): $(OBJS)
	@echo "$(CYAN)[EXEC]$(RESET) Linking $(NAME)..."
	@$(CC) $(INCLUDES) $(OBJS) $(LIBFTT) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)[SUCCESS]$(RESET) $(NAME) built successfully."

# Rule to compile object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)[OBJ]$(RESET) Compiling $@..."
	@$(CC) $(INCLUDES) -c $< -o $@

# For depe
-include $(OBJS:.o=.d)

# Clean rule
clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files"
	@rm -rf $(OBJS_DIR)
	@make -C $(SRCS_DIR)/libft clean

# Full clean rule (clean + remove executable)
fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removing $(NAME)..."
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "$(GREEN)[FCLEAN]$(RESET) $(NAME) removed successfully."

# Rebuild rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re run norm