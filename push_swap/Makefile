# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:43:47 by bantunes          #+#    #+#              #
#    Updated: 2022/09/28 15:17:04 by bantunes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f

SOURCE	=	main.c \
			check_string.c \
			edit_stacks.c \
			check_stacks.c \
			do_push_swap.c \
			chunk_chunky.c

OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	cd libft;make all
	cd libft;make bonus
	cd printf;make all
	$(CC) $(CFLAGS) $(OBJS) -I. -lft -lftprintf -o $(NAME) -L./libft -L./printf

clean:
	$(RM) $(OBJS)
	cd libft;make clean
	cd printf;make clean

fclean:	clean
	cd libft;make fclean
	cd printf;make fclean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re
