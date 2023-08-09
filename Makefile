# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 20:17:41 by jaehejun          #+#    #+#              #
#    Updated: 2023/08/09 18:51:36 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= test4.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)

re:
	make fclean
	make all