# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:22:50 by alphbarr          #+#    #+#              #
#    Updated: 2024/07/02 15:37:57 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/COLORS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
DEF_COLOR = \033[1;39m
WHITE_BOLD = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/NAME/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
NAME		= libftprintf.a

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-HEADERS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
HEADER		= ./inc/

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/DIRS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
OBJS_DIR	= objs/
SRCS_DIR	= src/

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/SRCS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
SRCS = ft_printf.c \
	   ft_basics.c \
	   ft_puntero.c \
	   ft_hexa.c
#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/OBJS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
OBJS		= $(addprefix $(OBJS_DIR), $(subst .c,.o,$(SRCS)))

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/DEPS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
DEPS		= $(addsuffix .d, $(basename $(OBJS)))

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/COMANDS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
RM			= rm -f
AR			= ar crs
MK			= Makefile
MKD			= mkdir -p
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I$(HEADER)

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/RULES/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c
	@$(MKD) $(dir $@)
	@printf "$(PINK)    \rCompiling: $(YELLOW)$(notdir $<)...$(DEF_COLOR)    \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

all				:
	@echo ""
	@$(MAKE) $(NAME)

$(NAME)			:	$(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)\nLIBRARY: '$(subst .a,,$@)' has been created$(DEF_COLOR)"

#$(NAME)			::
#	@echo "$(YELLOW)Nothing to be done for '$(subst .a,,$@)'$(DEF_COLOR)"

clean			:
	@$(RM) -r $(OBJS_DIR)

fclean			:	
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "$(RED)LIBRARY: '$(subst .a,,$(NAME))' has been removed$(DEF_COLOR)"

re				:
	@echo ""
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "$(CIAN)LIBRARY: '$(subst .a,,$(NAME))' has been remake$(DEF_COLOR)"

.PHONY: all clean fclean re

-include	$(DEPS)
