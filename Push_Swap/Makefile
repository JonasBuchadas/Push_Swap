CC=			gcc

CFLAGS=		-Wall -Werror -Wextra -g

NAME=		push_swap

SRCS=		main.c func_ptr.c swap.c rotate.c reverse_rotate.c push.c sort_small_alg.c smart_moves.c parser.c sort_large_alg.c smart_push_median.c smart_push_a.c check_a.c check_b.c

OBJS=		$(SRCS:.c=.o)

LIBFT_DIR=	./libft

LIBFT=		libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -I $(LIBFT_DIR) -o $@
	@echo "Push_Swap Program Created"

$(OBJS): $(SRCS) 
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $^

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
	@echo "Libft Library Created"
	
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(LIBFT_DIR)/$(LIBFT)
	@rm -f $(LIBFT)
	@echo "Libft Library Removed"
	@rm -f $(NAME) 
	@echo "Push_Swap Program Removed"

re: fclean all
