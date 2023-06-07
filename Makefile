# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 12:01:00 by gt-serst          #+#    #+#              #
#    Updated: 2023/06/07 10:53:02 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror

RM					= rm -rf

SRCS				= main.c \
					  parsing.c \
					  lst_utils.c \
					  check_av.c \
					  check_av_utils.c \
					  operations.c \
					  operations_utils.c \
					  operations_utils2.c \
					  sorting.c \
					  short_sorting.c \
					  sort_100.c \
					  sort_100_utils.c \
					  sort_stack.c \
					  sort_stack_utils.c \

OBJS				= $(addprefix srcs/, $(SRCS:.c=.o))

LIBFT_PATH			= ./libft

LIBFT				= $(LIBFT_PATH)/libft.a

.c.o:
					$(CC) $(CFLAGS) -c -I ./includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
					$(CC) -o $(NAME) $(OBJS) $(LIBFT)

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
