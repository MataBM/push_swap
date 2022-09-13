# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:43:47 by bantunes          #+#    #+#              #
#    Updated: 2022/09/13 15:01:16 by bantunes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFlags = -Wall -Wextra -Werror
RM = rm -f

SOURCE	=	main.c \
			check_string.c \
			edit_stacks.c

OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	-@ cd libft;make all
	-@ cd libft;make bonus
	-@ cd printf;make all
	-@ $(CC) $(CFLAGS) $(OBJS) -lft -lftprintf -o $(NAME) -L./libft -L./printf
	-@ cd libft;make fclean
	-@ cd printf;make fclean

clean:
	$(RM) $(OBJS)
	cd libft;make clean

fclean:	clean
	cd libft;make fclean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re
