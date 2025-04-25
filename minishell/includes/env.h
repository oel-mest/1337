/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:51:40 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/03 22:43:31 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

typedef struct s_envnode {
	char				*var;
	char				*value;
	struct s_envnode	*next;
}	t_envnode;

typedef struct s_split_state
{
	int	i;
	int	j;
	int	in_quotes;
	int	k;
}	t_split_state;

char		*process_dollar(const char *args, int *i, char *result,
				t_envnode *env_list);
void		ft_split_quotes_loop(char *str, t_split_state *state,
				char **result, char *word);
void		ft_split_quotes_loop(char *str, t_split_state *state,
				char **result, char *word);
char		**ft_split_quotes(char *str);
char		*ft_getenv(char *name, t_envnode *head);
t_envnode	*parse_envp(char **envp);
char		*expand_env_vars(char *args, t_envnode *env_list);
char		**expand_env_vars2(char **args, t_envnode *env_list);
char		*handle_lstatus_var(void);
char		*append_char2(char *str, char c);
char		*handle_var_expansion(char *args, int *i, t_envnode *env_list);
void		update_quotes(char c, int *in_single_quote, int *in_double_quote);
char		*process_dollar(const char *args, int *i, char *result,
				t_envnode *env_list);
char		*process_expansion(char *arg, t_envnode *env_list);
#endif