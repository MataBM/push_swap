# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:43:47 by bantunes          #+#    #+#              #
#    Updated: 2022/09/06 15:52:35 by bantunes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = push_swap

CC = cc
CFlags = -Wall -Wextra -Werror

C_SOURCE = 	main.c \
			check_strings.c

OBJS = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lft $(NAME) -L./libft

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re