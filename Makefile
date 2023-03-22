# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 12:01:00 by gt-serst          #+#    #+#              #
#    Updated: 2023/03/22 19:15:27 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror

RM					= rm -rf

SRCS				= main.c \
					  ft_parsing.c \
					  ft_lst_utils.c \
					  ft_check_av.c \
					  ft_check_av_utils.c \
					  ft_operations.c \
					  ft_operations_utils.c \
					  ft_operations_add.c \
					  ft_sorting.c \
					  ft_simple_sorting.c \
					  ft_sort_100.c \
					  ft_sort_100_utils.c \
					  ft_sort_stack.c \
					  ft_sort_stack_utils.c

OBJS				= $(addprefix srcs/, $(SRCS:.c=.o))

LIBFT_PATH			= ./libft

LIBFT				= $(LIBFT_PATH)/libft.a

.c.o:
					$(CC) $(CFLAGS) -c -I./includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
					${CC} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)

fclean: clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
