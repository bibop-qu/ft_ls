#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 14:34:58 by basle-qu          #+#    #+#              #
#    Updated: 2014/12/13 10:45:53 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS =	main.c \
		list.c \
		fct.c \
		fct2.c
OBJS =	main.o \
		list.o \
		fct.o \
		fct2.o
NAME = ft_ls 
CFLAG = -Wall -Wextra -Werror

.PHONY: all $(NAME) test clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	make -C libft/ clean	
	gcc -I includes -c $(CFLAG) $(SRCS)
	gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)

test: fclean
	gcc -I includes -c $(CFLAG) -g $(SRCS)
	gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	make clean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)