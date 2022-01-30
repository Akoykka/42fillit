# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 11:32:21 by akoykka           #+#    #+#              #
#    Updated: 2021/12/17 23:54:38 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = get_next_line.c main.c
	
OBJECTS =

INCLUDES = "get_next_line.h"

LIBRARIES = libft.a

all: $(NAME)

$(NAME): 
	gcc -o $(NAME) -Wconversion -Wall -Wextra -Werror $(SRCS) -L . -lft -I
	
clean:
	

fclean: clean
	rm -f $(NAME)

re: fclean all
	
norm:
	norminette $(SRCS)

run:
	./get_next_line