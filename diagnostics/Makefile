# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 14:40:27 by efriedma          #+#    #+#              #
#    Updated: 2018/04/22 20:34:10 by efriedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fillit

LIBFT := ../libft/

SRC = srcs/isinbounds.c srcs/readfile.c srcs/checkvalidity.c
SRC += srcs/solve.c srcs/makelink.c srcs/transform.c srcs/freemap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	gcc $(OBJ) -L. ../libft/libft.a srcs/main.c -o fillit

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re
