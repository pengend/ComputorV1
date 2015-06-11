#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/09 18:36:05 by pxia              #+#    #+#              #
#    Updated: 2015/06/10 18:54:37 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = computor
LIBFT_LIB = ./libft/libft.a
SRC_DIR	= ./src/
SRC	= main.c tools.c calq_branch.c puts.c check.c tri.c solution.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ	= $(SRCS:.c=.o)
INC	= -I ./libft -I ./includes
FLAGS = -Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) -lncurses

$(LIBFT_LIB):
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
