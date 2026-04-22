# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 12:33:06 by alphbarr          #+#    #+#              #
#    Updated: 2024/02/05 18:38:05 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs
RM = rm -rf

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror

ligth = \033[1m
G = \033[32m

NAME = libft.a
SRC =	ft_memset.c ft_bzero.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_isalpha.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)
LIB = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(AR) $(NAME) $(OBJ)
	echo "$(G)Library $(NAME) Done :)"

%.o: %.c Makefile $(LIB)
	$(CC) $(CCFLAGS) -c $< -o $@
	echo "$(ligth)$@ Compiled"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean
.SILENT:
