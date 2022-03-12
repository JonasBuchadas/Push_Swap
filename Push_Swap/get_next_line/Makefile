CC=		gcc

CFLAGS=	-Wall -Werror -Wextra -g

NAME=	get_next_line.a

SRCS=	get_next_line.c get_next_line_utils.c

OBJS=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $^
	@echo "GNL Library Created"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJS) $(OBJ_BONUS)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Library Removed"

re:	fclean all
