# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 14:29:07 by ezonda            #+#    #+#              #
#    Updated: 2018/12/12 16:11:38 by jebrocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c checker.c ft_fct.c algo.c algo_tools.c

OBJ = $(SRC: .c=.o)

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "compilation..."
	@$(CC) $(FLAGS) $(LIB) -I./libft $(OBJ) -I./includes -o $(NAME)
	@echo "done"

$(LIB):
	@echo "creating library...."
	@make -C libft/ fclean
	@make -C ./libft/
	@echo "done"

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS) -I./includes

clean:
	@echo "cleaning library...."
	@make -C libft/ clean
	@echo "done"

fclean: clean
	@echo "deleting ./fillit...."
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "done"

re: fclean all

.PHONY: clean fclean re all
