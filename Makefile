# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:56:40 by wmiszkie          #+#    #+#              #
#    Updated: 2024/04/22 15:08:47 by wmiszkie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgetnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS= 
OBJS = $(SRCS:.c=o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm - f $(OBJS)

fclean: clean
	rm - f $(NAME)

re: fclean all

.PHONY: all clean fclean re
