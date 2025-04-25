/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:23:37 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/13 13:03:21 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef enum e_node_type {
	NODE_COMMAND,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_SUB
}	t_node_type;

typedef struct s_output
{
	char			*file;
	struct s_output	*next;
	t_token_type	type;
}	t_output;

typedef struct s_cmd {
	char		*args;
	t_output	*input2;
	t_output	*output2;
	int			append;
	char		*heredoc;
}	t_cmd;

typedef struct s_redi {
	t_output	*input;
	t_output	*output;
	t_output	*heredoc;
	int			append;
}	t_redi;

typedef struct s_ast {
	t_node_type		type;
	t_cmd			*cmd;
	t_redi			*redi;
	struct s_ast	*left;
	struct s_ast	*right;
	int				inpar;
}	t_ast;

int			process_single_token(t_ast *node, t_token **tokens, int inpar);
t_ast		*parse_command(t_token **tokens, int inpar);
t_ast		*parse_logical(t_token **tokens, int inpar);
t_ast		*parse(t_token *tokens);
t_ast		*parse_pipeline(t_token **tokens, int inpar);
int			parse_single_redirection(t_token **tokens, t_redi *redi);
t_ast		*handle_parentheses(t_token **tokens, int inpar);
t_ast		*create_ast_node(t_node_type type, int inpar);
t_cmd		*create_cmd_node(void);
void		add_argument(t_cmd *cmd, const t_token *token);
t_output	*create_output_node(char *file, t_token_type type);
void		add_output(t_output **head, t_output *node);
int			is_special_token(t_token *token);
int			is_redirection_token(t_token *token);
int			is_word_or_quote(t_token_type type);
void		join_output(t_output *output, char *str);

#endif