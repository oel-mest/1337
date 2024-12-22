CC = cc
CFLAGS = -Wall -Wextra -Werror
################### mandatory #######################
SRC_FILES = helpers_1.c helpers_2.c helpers_3.c helpers_4.c \
            operations_1.c operations_2.c operations_3.c \
            utils_1.c utils_2.c utils_3.c utils_4.c main.c \
			control_1.c helpers_5.c control_2.c utils_5.c
OBJ_M = $(SRC_FILES:.c=.o)

HEADER_M = push_swap.h

NAME_M = push_swap
################## bonus ############################
BONUS_FILES = bonus/control_bonus_1.c bonus/control_bonus_2.c \
			bonus/operations_bonus_1.c bonus/operations_bonus_2.c \
			bonus/operations_bonus_3.c bonus/main.c \
			bonus/utils_bonus_1.c bonus/utils_bonus_2.c \
			bonus/utils_bonus_3.c bonus/utils_bonus_4.c 

OBJ_B = $(BONUS_FILES:.c=.o)

HEADER_B = bonus/push_swap_bonus.h

NAME_B = checker
################## get_next_line #####################
GET_FILES = bonus/get_next_line/get_next_line_utils.c \
			bonus/get_next_line/get_next_line.c

OBJ_GET = $(GET_FILES:.c=.o)

HEADER_GET = bonus/get_next_line/get_next_line.h

NAME_GET = get_next_line.a
######################################################

all: $(NAME_M)

$(NAME_M): $(OBJ_M)
	$(CC) $(CFLAGS) -o $(NAME_M) $(OBJ_M)

%.o: %.c $(HEADER_M)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus 

.bonus: $(OBJ_B) $(NAME_GET)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(NAME_GET)
	@touch .bonus

bonus/%.o: bonus/%.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_GET): $(OBJ_GET)
	ar rcs $(NAME_GET) $(OBJ_GET)

bonus/get_next_line/%.o: bonus/get_next_line/%.c $(HEADER_GET)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_M) $(OBJ_B) $(OBJ_GET) .bonus

fclean: clean
	rm -f $(NAME_M) $(NAME_B) $(NAME_GET)

re: fclean all

.PHONY: all clean fclean re bonus