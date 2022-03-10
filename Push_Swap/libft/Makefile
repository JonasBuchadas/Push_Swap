CC=		gcc

CFLAGS=	-Wall -Werror -Wextra

NAME=	libft.a

SRCS=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c ft_sort_int_tab.c \
		ft_min_int.c ft_max_int.c

OBJS=$(SRCS:.c=.o)

BONUS=	ft_lstnew.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS=$(BONUS:.c=.o)

CLISTS=	ft_cdlstnew.c ft_cdlstsize.c ft_cdlstlast.c\
		ft_cdlstadd_front.c ft_cdlstadd_back.c ft_cdlstdelone.c \
		ft_cdlstclear.c ft_cdlstiter.c

OBJ_CLISTS=$(CLISTS:.c=.o)

all: $(NAME)

bonus: $(OBJS) $(OBJ_BONUS) $(OBJ_CLISTS)
	@ar rcs $(NAME) $^ 
	@echo "Full Library Created"

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)
	@echo "Mandatory Library Created"

$(OBJS): $(SRCS) 
	@$(CC) $(CFLAGS) -c $^

$(OBJ_BONUS): $(BONUS) 
	@$(CC) $(CFLAGS) -c $^

$(OBJ_CLISTS): $(CLISTS) 
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJS) $(OBJ_BONUS) $(OBJ_CLISTS)
	@echo "Object Files Removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Library Removed"

re: fclean all
