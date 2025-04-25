/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:42:59 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/12 17:18:25 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
// # include <string.h>
# include <ctype.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <signal.h>
# include "../srcs/libft/libft.h"
# include "get_next_line.h"
# include <dirent.h> // for wildcard expansion

typedef struct s_exec_ctx
{
	t_cmd		*cmd;
	t_envnode	**envp;
	char		**args;
	char		*path;
	char		**envp_array;
	t_ast		*node;
}	t_exec_ctx;

typedef struct s_matches_ctx
{
	char	**matches;
	size_t	cnt;
	size_t	cap;
	DIR		*dir;
}	t_matches_ctx;

int			get_status(void);
char		*ft_getenv(char *name, t_envnode *head);
void		add_node(t_envnode **head, t_envnode *new_node);
t_envnode	*create_node(const char *env_entry);
void		set_status(int status);
int			execute_subshell(t_ast *node, t_envnode **envp);

// Builtin functions
int			is_builtin(char *cmd);
int			run_builtin(t_exec_ctx *ctx);
int			builtin_echo(char *args);
int			builtin_cd(char **args, t_envnode **envp);
int			builtin_pwd(void);
int			builtin_export(char **args, t_envnode **envp);
int			builtin_unset(char **args, t_envnode **envp);
int			builtin_env(t_envnode *envp);
int			builtin_exit(t_exec_ctx *ctx);
t_envnode	*find_env_var(t_envnode *envp, const char *var);

// Execution functions
char		**ft_split(char const *s, char c);
char		*search_command(char *cmd, t_envnode *envp);
int			execute_ast(t_ast *node, t_envnode **envp);
int			execute_command(t_ast *tree, t_envnode **envp);

// Redirection functions
int			redirect_output(t_output *input_list, int append);
int			redirect_input(t_output *input_list);
void		prepare_heredocs(t_ast *node, t_envnode **envp);
int			check_ambiguous_redirects(t_cmd *cmd, t_envnode *envp);
int			if_ambiguous(char *file, t_envnode *env_list);

// minishell
void		minishell(t_ast *root, t_envnode **envp);
void		handle_sigint(int sig);
int			check_if_folder(char *cmd);
char		*expand_line(char *line);
void		print_error(char *first, ...);

// command_utils.c
int			setup_context(t_exec_ctx *ctx, t_ast *tree, t_envnode **envp);
void		child_process(t_exec_ctx *ctx);
void		collect_heredoc(t_cmd *cmd, t_envnode **envp);
char		*remove_quotes(const char *str);
int			is_quoted_delimiter(const char *delimiter);
void		prepare_heredocs(t_ast *node, t_envnode **envp);
void		process_heredoc_input(int fd, char *clean_delimiter,
				int expand_vars, t_envnode **envp);
void		process_heredoc_entry(t_output *current, t_envnode **envp);
void		collect_heredoc(t_cmd *cmd, t_envnode **envp);
void		handle_heredoc_if_needed(t_cmd *cmd);
char		**envp_to_array(t_envnode *envp);
char		*process_initial_part(char *input, int *i);
void		append_char(char **str, char c);
void		execute_local_executable(char *cmd, char **args, char **envp);
void		hundle_awk(char **args);
void		hundle_awk2(char **args);
char		*remove_quotess(const char *str);
void		process_remaining_chars(char *input, int *i, char **result);
char		*remove_first_layer_quotes(char *input);
char		*get_first_word(char *str);
void		process_first_arg(char **arg);
void		process_quoted_arg(char **arg);

// builtins
int			is_builtin(char *cmd);
int			builtin_correction(void);
int			builtin_echo(char *args);
int			is_valid_var_name(const char *var);
t_envnode	*find_env_var(t_envnode *envp, const char *var);
void		set_pwd_oldpwd(t_envnode **envp, char *oldpwd);
int			builtin_correction(void);
void		hundle(char **home);
int			builtin_echo(char *args);
int			builtin_cd(char **args, t_envnode **envp);
int			builtin_pwd(void);
int			builtin_export(char **args, t_envnode **envp);
int			builtin_unset(char **args, t_envnode **envp);
int			builtin_env(t_envnode *envp);
int			builtin_correction(void);
void		print_env_export(t_envnode *envp, char **args);
char		*strip_quotes(const char *s);
int			process_export_arg_no_eq(char *arg, t_envnode **envp);
char		*extract_var_name(char *arg, size_t *var_len);
int			update_export_var(char *var_name, char *arg, t_envnode **envp);

// wildcards
int			match_pattern(const char *p, const char *s);
void		check_and_add(const char *pattern, struct dirent *entry,
				t_matches_ctx *ctx);
size_t		compute_total(char **matches);
char		*build_result(char **matches, size_t total);
char		**expand_wildcard(const char *pattern);
char		*expand_token(const char *token);
char		*expand_line(char *line);
int			is_all_stars(const char *s);
int			max(int a, int b);

// pipes
int			execute_pipe(t_ast *left, t_ast *right, t_envnode **envp);

// ast
int			exec_command_node(t_ast *node, t_envnode **envp);
int			exec_pipe_node(t_ast *node, t_envnode **envp);
int			exec_and_node(t_ast *node, t_envnode **envp);
int			exec_or_node(t_ast *node, t_envnode **envp);
int			exec_sub_node(t_ast *node, t_envnode **envp);
void		collect_heredoc2(t_redi *redi, t_envnode **envp);
void		handle_heredoc_if_needed2(t_redi *redi);

void		free_withoutexit(t_exec_ctx *ctx);

#endif