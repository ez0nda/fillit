# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 14:29:07 by ezonda            #+#    #+#              #
#    Updated: 2018/12/09 15:10:52 by ezonda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

SRC = main.c checker.c ft_fct.c algo.c

OBJ = $(SRC: .c=.o)

LIB_PATH = libft/

LDFLAGS = -Llibft/

LDLIBS = -ltermcap

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) -I./libft/includes -I./include -I./include -I./includesss
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

lib:
	make -C $(LIB_PATH)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) -I./includes

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
