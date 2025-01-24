# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 14:21:23 by vfidelis          #+#    #+#              #
#    Updated: 2025/01/21 22:12:36 by vfidelis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

FUNCTIONS = lib/ft_free.c \
			lib/ft_strjoin.c \
			lib/ft_strlen.c \
			lib/ft_memcpy.c \
			lib/ft_split.c \
			lib/ft_strncmp.c \
			ft_utils.c \
			pipex.c

OBJS =	lib/ft_free.o \
		lib/ft_strjoin.o \
		lib/ft_strlen.o \
		lib/ft_memcpy.o \
		lib/ft_split.o \
		lib/ft_strncmp.o \
		ft_utils.o \
		pipex.o \

LIB = pipex.a

NAME = pipex

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o) -g
all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(LIB) $(OBJS)
	cc $(FLAGS) pipex.c pipex.a -o $(NAME) -g
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS) $(LIB) $(NAME)

re: fclean all