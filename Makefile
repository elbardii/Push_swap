CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = initialize_stack.c main.c operations.c \
       sort.c validation.c utils.c stack_operations.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re