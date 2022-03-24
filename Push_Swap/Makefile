CC=			gcc

CFLAGS=		-Wall -Werror -Wextra

NAME=		push_swap

BONUS=		checker

SRCS=		push_swap.c \
			sort_algs.c \
			sort_medium_alg.c \
			sort_medium_comb.c \
			sort_large_alg.c \
			check_receiver_stack.c \
			check_sender_stack.c \
			execute_moves.c \
			smart_push.c \
			push_median_a.c \
			push_median_b.c \
			sort_stack_print.c

OBJS=		$(SRCS:.c=.o)

SRC_BONUS=	checker.c

OBJ_BONUS=	$(SRC_BONUS:.c=.o)

SRC_BOTH=	func_ptr.c \
			swap.c rotate.c \
			reverse_rotate.c \
			push.c \
			smart_moves.c \
			parser.c

OBJ_BOTH=	$(SRC_BOTH:.c=.o)

LIBFT_DIR=	./libft

LIBFT=		libft.a

INC=		-I $(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS) $(OBJ_BOTH) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(INC) -o $@
	@echo -e "$(GREEN)Checker Program Created$(DEFAULT)"

$(NAME): $(OBJS) $(OBJ_BOTH) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(INC) -o $@
	@echo -e "$(GREEN)Push_Swap Program Created$(DEFAULT)"

$(OBJS): $(SRCS) 
	@$(CC) $(CFLAGS) $(INC) -c $^

$(OBJ_BONUS): $(SRC_BONUS)
	@$(CC) $(CFLAGS) $(INC) -c $^

$(OBJ_BOTH): $(SRC_BOTH)
	@$(CC) $(CFLAGS) $(INC) -c $^

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
	@echo -e "$(GREEN)Libft Library Created$(DEFAULT)"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS) $(OBJ_BONUS) $(OBJ_BOTH)
	@echo -e "$(RED)Object Files Removed$(DEFAULT)"

fclean: clean
	@rm -f $(LIBFT_DIR)/$(LIBFT)
	@rm -f $(LIBFT)
	@echo -e "$(RED)Libft Library Removed$(DEFAULT)"
	@rm -f $(NAME)
	@echo -e "$(RED)Push_Swap Program Removed$(DEFAULT)"
	@rm -f $(BONUS)
	@echo -e "$(RED)Checker Program Removed$(DEFAULT)"

re: fclean all

GREEN= \033[1;32m
RED= \033[1;31m
DEFAULT= \033[0m