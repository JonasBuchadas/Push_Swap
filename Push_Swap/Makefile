CC=			gcc

CFLAGS=		-Wall -Werror -Wextra -g

NAME=		push_swap

BONUS=		checker_1		

SRCS=		push_swap.c sort_small_alg.c sort_large_alg.c push_median.c \
			smart_push_a.c check_receiver_stack.c check_sender_stack.c execute_moves.c

OBJS=		$(SRCS:.c=.o)

SRC_BONUS=	checker.c

OBJ_BONUS=	$(SRC_BONUS:.c=.o)

SRC_BOTH=	func_ptr.c swap.c rotate.c reverse_rotate.c push.c \
			smart_moves.c parser.c

OBJ_BOTH=	$(SRC_BOTH:.c=.o)

LIBFT_DIR=	./libft

LIBFT=		libft.a

GNL_DIR=	./get_next_line

GNL=		get_next_line.a

INC=		-I $(LIBFT_DIR) -I $(GNL_DIR)

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS) $(OBJ_BOTH) $(LIBFT) $(GNL)
	@$(CC) $(CFLAGS) $^ $(INC) -o $@
	@echo "Checker Program Created"

$(NAME): $(OBJS) $(OBJ_BOTH) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(INC) -o $@
	@echo "Push_Swap Program Created"

$(OBJS): $(SRCS) 
	@$(CC) $(CFLAGS) $(INC) -c $^

$(OBJ_BONUS): $(SRC_BONUS)
	@$(CC) $(CFLAGS) $(INC) -c $^

$(OBJ_BOTH): $(SRC_BOTH)
	@$(CC) $(CFLAGS) $(INC) -c $^

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
	@echo "Libft Library Created"

$(GNL):
	@make bonus -C $(GNL_DIR)
	@cp $(GNL_DIR)/$(GNL) $(GNL)
	@echo "Get_Next_Line Library Created"

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	@rm -f $(OBJS) $(OBJ_BONUS) $(OBJ_BOTH)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(LIBFT_DIR)/$(LIBFT)
	@rm -f $(LIBFT)
	@echo "Libft Library Removed"
	@rm -f $(GNL_DIR)/$(GNL)
	@rm -f $(GNL)
	@echo "Get_Next_Line Library Removed"
	@rm -f $(NAME)
	@echo "Push_Swap Program Removed"
	@rm -f $(BONUS)
	@echo "Checker Program Removed"

re: fclean all
