CC=		gcc

CFLAGS=	-Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)

BUFFER_SIZE= 5

NAME=	get_next_line.a

SRCS=	get_next_line.c get_next_line_utils.c

OBJS=	$(SRCS:.c=.o)

BONUS=	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_BONUS=	$(BONUS:.c=.o)

all:	$(NAME)

bonus:	$(OBJS_BONUS)
	@ar rcs $(NAME) $^
	@echo "GNL_Bonus Library Created"

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $^
	@echo "GNL Library Created"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $^

$(OBJ_BONUS): $(BONUS)
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJS) $(OBJ_BONUS)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Library Removed"

re:	fclean all
