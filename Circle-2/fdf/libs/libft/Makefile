# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:29:05 by alphbarr          #+#    #+#              #
#    Updated: 2024/07/02 16:18:35 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
AR = ar rcs
RM = rm -rf

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror -I../includes

SOURCES_DIRECTORY = ./src/

NAME = libft.a

SRC_LIST = $(wildcard $(SOURCES_DIRECTORY)*.c)

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SRC_LIST))
OBJDIR = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(notdir $(SRC_LIST)))
OBJS = $(addprefix $(OBJDIR), $(OBJS_LIST))

LIB = src/libft.h\
	src/get_next_line.h

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(AR) $@ $(OBJS)
	@echo "Library $@ Done :)"

$(OBJDIR)%.o: $(SOURCES_DIRECTORY)%.c Makefile $(LIB)
	@mkdir -p $(@D)
	@echo "$(GREEN) Compiling... $<..."
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(RED) $@ created!"

clean:
	@echo "Remove *.o"
	@${RM} -r $(OBJDIR)
	@echo "Done !"

fclean: clean
	@echo "Remove $(NAME)"
	@${RM} $(NAME)
	@echo "Done !"

re: fclean all
