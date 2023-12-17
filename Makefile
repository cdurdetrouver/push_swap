# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 12:49:16 by gbazart           #+#    #+#              #
#    Updated: 2023/12/17 15:36:06 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a
SRC_DIR = ./srcs
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:.c=.o)

NAMEB = checker
SRCB_DIR = ./srcsb
SRCB = $(shell find $(SRCB_DIR) -name '*.c')
OBJB = $(SRCB:.c=.o)


all: $(NAME) $(NAMEB)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $(OBJ) $(LIBFT) -o $(NAME) -g

bonus: $(OBJB)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $(OBJB) $(LIBFT) -o $(NAMEB) -g

$(NAMEB): bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

norminette:
	norminette $(SRC_DIR)
	norminette ./includes/

clean:
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
