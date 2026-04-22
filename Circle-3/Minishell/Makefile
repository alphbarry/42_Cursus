# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 20:20:40 by cgomez-z          #+#    #+#              #
#    Updated: 2025/04/03 21:03:52 by alpha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<--------------------------------->COLORS<----------------------------------->#
DEF_COLOR	=	\033[1;99m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
PINK		=	\033[1;95m
CIAN		=	\033[1;96m

#<--------------------------------->NAME<------------------------------------>#
NAME		=	minishell

#<-------------------------------->LIBRARY<---------------------------------->#
LIBRARY	=	./libs/
LIB_A		=	./libs/libft/libft.a 
LIB_SEARCH	=	-L./libs/libft 
GNL_A		=	./libs/gnl/libgnl.a
GNL_SEARCH	=	-L./libs/gnl

LIB_A		=	./libs/libft/libft.a
LIB_SEARCH	=	-L./libs/libft
GNL_A		=	./libs/gnl/libgnl.a
GNL_SEARCH	=	-L./libs/gnl

#<-------------------------------->HEADERS<---------------------------------->#
HEADER		=	./inc/
LIBFT_H		=	./libs/libft/src/
GNL_H		=	./libs/gnl/

#<--------------------------------->DIRS<------------------------------------>#
SRC_DIR		=	src/
OBJ_DIR		=	objects/

#<--------------------------------->FILES<---------------------------------->#
FILES		=	main.c \
			tokens/tokenize.c \
			tokens/utils_tokenize.c \
			tokens/token_list.c \
			tokens/tokens_count.c \
			tokens/tokens_error.c \
			builtins/builtins.c \
			builtins/pwd.c \
			builtins/env.c \
			builtins/exit.c \
			builtins/export.c \
			builtins/unset.c \
			builtins/echo.c \
			builtins/cd.c \
			builtins/built_utils.c \
			lst_utils/ft_lstadd_back_node.c \
			lst_utils/ft_lstlast_node.c \
			utils/error.c \
			utils/free.c \
			utils/clean.c \
			utils/frees.c \
			utils/env.c \
			utils/env_utils.c \
			utils/error_handler.c \
			exec/cmd_exec.c \
			exec/exec_shell.c \
			exec/tokens_exec.c \
			signals/signals.c \
			expand/token_expand.c \
			expand/token_expand_utils.c \
			expand/dollar_expand.c \
			expand/dollar_expand_utils.c \
			expand/split_token.c \
			expand/split_token_utils.c \
			redirs/io_redirs.c \
			redirs/io_redirs_utils.c \
			redirs/hdoc_dollar.c \
			redirs/hdoc_handling.c \
			cmd/cmd.c \
			cmd/cmd_filler.c \
			cmd/cmd_utils.c \
			cmd/cmd_utils1.c \
			cmd/cmd_exec_utils.c \
			heredocs/get_hdocs.c \
			heredocs/get_hdocs_utils.c \
			heredocs/heredocs.c \
			heredocs/heredocs_utils.c \
			
#<--------------------------------->SRCS<----------------------------------->#
SRCS		=	$(addprefix $(SRC_DIR), $(FILES))

#<----------------------------->OBJS && DEPS<------------------------------->#
OBJS		=	$(addprefix $(OBJ_DIR), $(subst .c,.o,$(FILES)))
DEPS		=	$(subst .o,.d,$(OBJS))

#<-------------------------------->COMANDS<---------------------------------->#
INCLUDE		=	-I$(HEADER) -I$(LIBFT_H) -I$(GNL_H)
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile
CFLAGS		=	#-Wall -Wextra -Werror -O3#
CC			=	cc -g
CFLAGS		=	-Wall -Wextra -Werror  #-fsanitize=address
MKFLAGS		=	--no-print-directory

#<--------------------------------->RULES<----------------------------------->#
$(OBJ_DIR)%.o	:$(SRC_DIR)%.c $(LIB_A) $(GNL_A) $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)    \rCompiling: $(YELLOW)$(notdir $<)...$(DEF_COLOR)       \r"
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

all				:
	@$(MAKE) $(MKFLAGS) -C $(LIBRARY)
	@$(MAKE) $(MKFLAGS) $(NAME)


$(NAME)			:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_A) $(GNL_A) -lreadline -o $@
	@echo "\n$(GREEN)minishell has been compiled$(DEF_COLOR)"

clean			:
	@$(MAKE) $(MKFLAGS) clean -C $(LIBRARY)
	@$(RM) $(OBJ_DIR) $(B_OBJ_DIR)
	@echo ""
	@echo "$(RED)All OBJS && DEPS has been removed$(DEF_COLOR)"
	@echo ""

fclean			:
	@$(MAKE) $(MKFLAGS) clean
	@$(MAKE) $(MKFLAGS) fclean -C $(LIBRARY)
	@$(RM) $(NAME) $(B_NAME)
	@echo ""
	@echo "$(RED)Program has been removed$(DEF_COLOR)"

re				:
	@$(MAKE) $(MKFLAGS) fclean
	@$(MAKE) $(MKFLAGS) all
	@echo ""
	@echo "$(CIAN)minishell has been recompiled$(DEF_COLOR)"

.PHONY			: all clean fclean re

-include		$(DEPS)
