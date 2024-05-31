# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 08:34:41 by pmihangy          #+#    #+#              #
#    Updated: 2024/05/24 15:01:59 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ARGUMENTS
NAME = push_swap
LIBFT_NAME = libft/libft.a
SOURCES = main.c errors.c stack.c del_el_in_stack.c \
	push_in_instructions.c swap.c push.c rotate.c \
	reverse_rotate.c push_swap.c quicks_sort.c is_functions.c \
	my_lst_manip.c tiny_sort.c show_instructs.c str_manip.c \
	donto_sort.c min_max.c push_swap_utils.c search_big_than.c \
	cost_count.c cases_sort.c push_n_exec.c cases_sort_next.c \
	ft_free.c sort_five.c stack_next.c push_swap_utils2.c
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

#RULES
all: $(NAME)

$(NAME): $(LIBFT_NAME) $(SOURCES)
	$(CC) $(SOURCES) -L. -lft -o $(NAME)

$(LIBFT_NAME):
	make -C ./libft bonus
	cp ./libft/libft.a .

clean:
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -rf libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
