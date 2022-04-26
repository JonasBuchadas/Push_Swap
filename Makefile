### COMPILATION ###
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra

### EXECUTABLES ###
NAME=		push_swap
BONUS=		checker

### PATHS ###
LIBFT_PATH=	./libft/
INCL_PATH=	incl/
SRCS_PATH=	srcs/
OBJS_PATH=	objs/

### SOURCE FILES ###
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
SRCS_NAME=	$(addprefix $(SRCS_PATH), $(SRC_NAME) $(SRCS))
SRCS_BONUS=	$(addprefix $(SRCS_PATH), $(SRC_BONUS) $(SRCS))

### OBJECT FILES ###
OBJ_NAME=	$(SRC_NAME:.c=.o)
OBJ_BONUS=	$(SRC_BONUS:.c=.o)
OBJS=		$(SRCS:.c=.o)
OBJS_NAME=	$(addprefix $(OBJS_PATH), $(OBJ_NAME) $(OBJS))
OBJS_BONUS=	$(addprefix $(OBJS_PATH), $(OBJ_BONUS) $(OBJS))

### LIBFT ###
LIBFTMAKE=  make bonus --silent -C $(LIBFT_PATH)
LIBFT=      -L$(LIBFT_PATH) -lft

### INCLUDES ###
INC=		-I $(LIBFT_PATH)$(INCL_PATH) -I $(INCL_PATH)

### COLOURS ###
GREEN= \033[1;32m
RED= \033[1;31m
DEFAULT= \033[0m

### IMPLICT RULES ###
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

### ACTIVE RULES ###
all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS_PATH) $(OBJS_NAME) 
	@$(LIBFTMAKE)
	@$(CC) $(CFLAGS) $(OBJS_NAME) $(INC) $(LIBFT) -o $@
	@echo -e "$(GREEN)$@ Program created$(DEFAULT)"

$(BONUS): $(OBJS_PATH) $(OBJS_BONUS)
	@$(LIBFTMAKE)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(INC) $(LIBFT) -o $@
	@echo -e "$(GREEN)$@ Program created$(DEFAULT)"

$(OBJS_PATH):
	@mkdir -p $@

clean:
	@make $@ --silent -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@echo -e "$(RED)Object files removed$(DEFAULT)"

fclean: clean
	@make $@ --silent -C $(LIBFT_PATH)
	@echo -e "$(RED)Libft removed$(DEFAULT)"
	@rm -f $(NAME) $(BONUS)
	@echo -e "$(RED)Programs removed$(DEFAULT)"

re: fclean all

### NORMINETTE ###
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH)
	@norminette -R CheckDefine $(INCL_PATH)

.PHONY:	all clean fclean bonus re
