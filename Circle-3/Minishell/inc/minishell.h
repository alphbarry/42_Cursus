/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:25:25 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:17:17 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/gnl/get_next_line.h"
# include "../libs/libft/src/libft.h"
# include "./structs.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

extern int		g_err;

// Tokens
char			*token_break(char *s, char *sep);
t_token_type	get_token_type(char *t);
void			free_tokens(t_token *tokens);
void			free_token_list(t_token **list);
int				count_tokens(char *s, char *sep);
int				check_token_syntax(t_data *data, t_token *tokens);
t_token			**create_tokens_list(t_token *tokens);
t_error			tokenize(char *s, t_data *data);

// Exec
void			exec_shell(t_data *data);
int				cmd_exec(t_data *data, t_token *tokens);
t_error			exec_token(t_data *data);

// Expand
char			*end_var(char *s);
void			update_quote_status(int *i_q, char c);
int				expand_env_var(t_token *tok, t_data *data, char *t,
					t_token_type prev);
int				expand_dollar_var(t_token *exp_t, t_data *data,
					t_token *curr_tok, int i);
int				check_no_lit_space(t_token *tok);
t_token_type	get_last_token_type(t_token *new_tokens);
int				init_expansion_data(int *i, t_token **new_tokens, t_data *data,
					t_token *exp_t);
int				tokenslen(t_token *t);
t_token			*tokens_join(t_token *t1, t_token *t2);
t_token			*tokens_join_free(t_token *t1, t_token *t2);
t_token			*split_expanded_token(t_token *t);
char			*find_unquoted_sep(t_token *t, int k, char *sep);
t_token			*token_expander(t_data *data, t_token *tokens);
void			fill_tokens_without_q(size_t wlen, t_token *t, int j,
					t_token *ret_one);
int				allocate_new_token(t_token *t, int *k, t_token *ret, int *i);

/*Crispy*/

int				which_built(t_data *data, int i, int ex);
int				do_echo(t_token *tokens);
int				get_pwd(void);
void			print_env(char **env);
int				count_env(char **env);
char			**create_env(void);
int				do_exit(t_data *data, char **args);
int				is_space(char c);
int				is_char(char c);
char			*get_var(const char *s);
char			*get_value(const char *s);
void			pointer_to_lst(t_data *data);
int				update_env(t_env **env, const char *key, const char *val);
int				ft_cd(t_token *tokens, t_data *data);
int				ft_export(t_token *tokens, t_data *data, int status);
int				ft_unset(t_token *tokens, t_data *data);
int				print_env_list(t_env *env_list);
void			print_export(t_env *env_list);
void			ft_lstadd_back_node(t_env **lst, t_env *new_lst);
t_env			*ft_lstlast_node(t_env *lst);
void			free_all(t_data *data);

// Utils
char			*get_env(t_data *data, char *key);
char			**conv_to_execv_format(t_data *data);
t_env			*allocate_env_struct(char **envp);
void			exec_shell(t_data *data);

// cmds
int				is_path(char *str);
void			exec_cmd(t_data *data, int i);
pid_t			exec_piped_cmds(t_data *data, int *end);
int				exec_cmds(t_data *data);
int				setup_cmd_io(t_cmd *cmds, t_token *tokens, int i);
int				fill_cmd(t_data *data, int *i, t_token *tokens);
int				save_cmd(t_data *data, int *i, int *j, t_token *ts);

// Free
void			free_tokens(t_token *tokens);
void			free_token_list(t_token **token_list);
void			free_cmds(t_cmd *cmds);
void			free_double(char **s);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin3_free(char *s1, char *s2, char *s3);
void			on_error_free(char *cmd_num, char *hdoc_num);
void			free_hdocs(t_hdoc **hdocs);
void			free_env(t_env *env);
void			clear_shell_status(t_data *data);

// Error
void			print_error(char *cmd, char *var, char *error);
void			print_perror(char *msg, int error);
void			open_error(char *filename);
void			display_token_error(char *token);
void			error_handler(t_data *data, t_error error);

// Signals
void			process_signals(int status);
void			handle_sigint(int sig);
void			handle_sigint_hdoc(int sig);
void			reset_signals(void);

// Redirs
char			*expand_dollar_variables(char *l, t_data *datae);
int				handle_hdoc_expansion(t_data *data);
void			assign_or_close_fds(t_data *data, int *i, int *fdio);
int				open_all_files(t_data *data);

// Hdocs
t_error			init_hdocs(t_data *data);
int				check_latest_hdoc(t_token *t);
char			*build_temp_hdoc_filename(t_data *data, int *i);
int				simulate_hdoc(char *eof);
t_error			manage_hdocs_processing(t_data *data);
int				allocate_hdocs(t_data *data);

#endif
