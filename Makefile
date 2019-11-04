# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 23:23:05 by medesmon          #+#    #+#              #
#    Updated: 2019/04/11 20:20:03 by tlynesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ft_main.c \
	   fill.c \
	   ft_validator.c \
	   lst.c \
	   plus.c

OBJ = $(SRCS:.c=.o)

LIB = libft/libft.a

FLS = -Wall -Werror -Wextra

INCLUDES = libft/libft.a -I libft -I includes/libft.h

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@gcc -o $(NAME) $(FLS) $(OBJ) $(INCLUDES)

$(LIB):
	@make -C libft/

.c.o:
	gcc $(FLS) -c $< -o $@ -I libft -I libft/includes

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
