CC=			gcc

CFLAGS=		-Wall -Werror -Wextra

NAME=		push_swap

BONUS=		checker

SRC_NAME=	$(NAME).c

SRC_BONUS=	$(BONUS).c

SRCS=		sort_algs.c \
			sort_medium_alg.c \
			sort_medium_comb.c \
			sort_large_alg.c \
			check_receiver_stack.c \
			check_sender_stack.c \
			execute_moves.c \
			smart_push.c \
			push_median_a.c \
			push_median_b.c \
			sort_stack_print.c \
			func_ptr.c \
			swap.c rotate.c \
			reverse_rotate.c \
			push.c \
			smart_moves.c \
			parser.c

OBJ_NAME=	$(SRC_NAME:.c=.o)

OBJ_BONUS=	$(SRC_BONUS:.c=.o)

OBJS=		$(SRCS:.c=.o)

LIBFT_DIR=	./libft/

LIBFTMAKE=  make bonus --silent -C $(LIBFT_DIR)

LIBFT=      -L$(LIBFT_DIR) -lft

LIB=		$(NAME).a

INC=		-I $(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ_NAME) $(LIB) 
	@$(LIBFTMAKE)
	@$(CC) $(CFLAGS) $(OBJ_NAME) $(INC) $(LIB) $(LIBFT) -o $@
	@echo -e "$(GREEN)$@ Program created$(DEFAULT)"

$(BONUS): $(OBJ_BONUS) $(LIB) 
	@$(LIBFTMAKE)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INC) $(LIB) $(LIBFT) -o $@
	@echo -e "$(GREEN)$@ Program created$(DEFAULT)"

$(OBJ_NAME): $(SRC_NAME) 
	@$(CC) $(CFLAGS) $(INC) -c $^

$(OBJ_BONUS): $(SRC_BONUS)
	@$(CC) $(CFLAGS) $(INC) -c $^

$(OBJS): $(SRCS) 
	@$(CC) $(CFLAGS) $(INC) -c $^

$(LIB): $(OBJS)
	@ar rcs $@ $^

clean:
	@make $@ --silent -C $(LIBFT_DIR)
	@rm -f $(OBJ_NAME) $(OBJS) $(OBJ_BONUS)
	@echo -e "$(RED)Object files removed$(DEFAULT)"

fclean: clean
	@make fclean --silent -C $(LIBFT_DIR)
	@echo -e "$(RED)Libft removed$(DEFAULT)"
	@rm -f $(NAME) $(BONUS) $(LIB)
	@echo -e "$(RED)Programs removed$(DEFAULT)"

re: fclean all

.PHONY:	all clean fclean bonus re

GREEN= \033[1;32m
RED= \033[1;31m
DEFAULT= \033[0m
