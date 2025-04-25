/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:29:34 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/03 12:25:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "minishell.h"

void	free_cmd(t_cmd *cmd);
void	free_ast(t_ast *node);
void	free_tokens(t_token *tokens);
void	free_env_list(t_envnode *env_list);
void	free_env_list2(t_envnode **env_list);
void	free_redi(t_redi *redi);
void	free_output_list(t_output *output_list);
void	free_split(char **split);

#endif