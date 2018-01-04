# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cammapou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 11:06:18 by cammapou          #+#    #+#              #
#    Updated: 2017/12/28 15:17:36 by cammapou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	ft_tools.c \
		ft_init_map.c \
		ft_modify_list.c \
		ft_print.c \
		ft_read_file.c \
		ft_solver.c

LIB = Libft

OBJ = $(SRC:.c=.o)

CC = gcc

RM = @/bin/rm -f

LIBPATH = Libft/libft.a

LIBOBJ = Libft/objs

CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(CC) -o $(NAME) $(OBJ) $(LIBPATH)
	@echo "\033[32m[ 100% ] Compilation Done\033[0m"

clean:
	@make fclean -C $(LIB)
	@$(RM) $(OBJ)
	@echo "\033[32m[ 100% ] Removed Objects Files\033[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all
