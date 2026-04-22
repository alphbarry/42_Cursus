/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:08:17 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 22:34:16 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/libft/src/libft.h"

typedef enum e_error
{
	NULL_ERR,
	SYNTAX_ERR,
	LEFT_Q_ERR,
	MALLOC_ERR,
	DUP2_ERR,
	FORK_ERR,
	PIPE_ERR,
	HDOC_LIMIT_ERR,
	OPEN_ERR,
	CLOSE_ERR,
}					t_error;

typedef enum e_token_type
{
	TOKEN,
	HDOC,
	REDIR,
	REDIR_ERROR,
	PIPE,
	AND,
	OR,
}					t_token_type;

/*
 * expand -- for hdoc only!
 */
typedef struct s_redir_io
{
	int				in;
	int				dup_fd;
	char			*filename;
	int				expand_flag;
}					t_redir_io;

typedef struct s_cmd
{
	char			**cmd;
	t_redir_io		*redir_info;
	int				input_fd;
	int				output_fd;
	int				error_redir_pos;
}					t_cmd;

typedef struct s_token
{
	char			*token;
	int				*literal;
	t_token_type	type;
}					t_token;

typedef struct s_env
{
	char			*env_key;
	char			*env_value;
	int				export_flag;
	int				join_flag;
	struct s_env	*next;
}					t_env;

/*
 * expand? yeah -> we expand $ inside
 * nah -> we don't
 * determined by whether the hdoc str is in quotations or no (wow)
 */
typedef struct s_hdoc
{
	char			*str;
	int				curr;
	int				expand;
}					t_hdoc;

typedef struct s_data
{
	t_token			*tokens;
	t_token			**tokens_list;
	t_cmd			*cmds;
	t_hdoc			**hdcs;
	t_error			aux_error;
	int				exit_status;
	int				curr_cmd;
	int				hdoc_count;
	int				tokens_count;
	int				total_hdocs;
	int				sp_hdoc;
	int				in_fd;
	int				out_fd;
	int				error_tok_pos;
	char			*hdoc_id;
	char			*error_tok_name;
	char			*aux_path;
	char			**env_copy;
	t_env			*env;
}					t_data;

#endif
