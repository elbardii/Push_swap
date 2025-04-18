# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 06:00:00 by isel-bar          #+#    #+#              #
#    Updated: 2025/04/18 18:31:13 by isel-bar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = main_program.c \
       stack_initialization.c \
       stack_manipulation.c \
       sorting_algorithms.c \
       input_validation.c \
       stack_element_operations.c \
       stack_sorting_helpers.c

OBJS = main_program.o \
       stack_initialization.o \
       stack_manipulation.o \
       sorting_algorithms.o \
       input_validation.o \
       stack_element_operations.o \
       stack_sorting_helpers.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re