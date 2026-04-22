# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:22:50 by alphbarr          #+#    #+#              #
#    Updated: 2024/03/08 12:26:00 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs
RM = rm -rf

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror


NAME = libftprintf.a

SRC = ft_basics.c ft_hexa.c ft_printf.c ft_puntero.c

OBJ = $(SRC:.c=.o)

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(AR) $@ $(OBJ)
	@echo "Library $@ Done :)"

%.o: %.c Makefile $(LIB)
	@echo "Compiling... $<..."
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$@ created!"

clean:
	@echo "Remove *.o"
	@${RM} ${OBJ}
	@echo "Done !"

fclean: clean
	@echo "Remove $(NAME)"
	@${RM} $(NAME)
	@echo "Done !"

re: fclean all

.PHONY: all clean re fclean
