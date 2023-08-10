# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 20:17:41 by jaehejun          #+#    #+#              #
#    Updated: 2023/08/10 22:08:31 by jaehejun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= so_long.c get_next_line.c get_next_line_utils.c ft_split.c
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