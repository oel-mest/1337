/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:00:30 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/05 16:13:25 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_exit_f(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

t_envnode	*create_node(const char *env_entry)
{
	t_envnode	*node;
	char		*eq;
	size_t		name_len;

	node = malloc(sizeof(t_envnode));
	if (!node)
		return (NULL);
	eq = ft_strchr(env_entry, '=');
	if (eq == NULL)
	{
		node->var = ft_strdup(env_entry);
		node->value = ft_strdup("");
	}
	else
	{
		name_len = eq - env_entry;
		node->var = malloc(name_len + 1);
		if (!node->var)
			return (free(node), NULL);
		ft_strncpy(node->var, env_entry, name_len);
		node->var[name_len] = '\0';
		node->value = ft_strdup(eq + 1);
	}
	node->next = NULL;
	return (node);
}

void	add_node(t_envnode **head, t_envnode *new_node)
{
	t_envnode	*current;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

char	*ft_getenv(char *name, t_envnode *head)
{
	char	*value;

	value = NULL;
	while (head != NULL)
	{
		if (ft_strcmp(name + 1, head->var) == 0)
		{
			value = ft_strdup(head->value);
			break ;
		}
		head = head->next;
	}
	if (value == NULL)
		return (NULL);
	else
		return (value);
}

t_envnode	*parse_envp(char **envp)
{
	t_envnode	*result;
	t_envnode	*node;
	int			i;

	result = NULL;
	node = NULL;
	i = 0;
	while (envp[i])
	{
		node = create_node(envp[i]);
		if (!node)
		{
			free_env_list(result);
			ft_exit_f("Malloc error");
		}
		add_node(&result, node);
		i++;
	}
	return (result);
}
