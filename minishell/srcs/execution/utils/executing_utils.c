/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:35:42 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/13 13:07:24 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*join_path(const char *dir, const char *cmd)
{
	size_t	len;
	char	*full;

	len = ft_strlen(dir) + 2 + ft_strlen(cmd);
	full = malloc(len + 1);
	if (!full)
		return (NULL);
	if (cmd[0] == '\0')
	{
		full[0] = '\0';
		return (full);
	}
	full[0] = '\0';
	ft_strcat(full, dir);
	ft_strcat(full, "/");
	ft_strcat(full, cmd);
	return (full);
}

int	check_if_folder(char *cmd)
{
	struct stat	statbuf;

	if (stat(cmd, &statbuf) == -1)
	{
		set_status(1);
		return (2);
	}
	if (statbuf.st_mode & S_IFDIR)
	{
		print_error(cmd, ": is a directory", NULL);
		set_status(126);
		return (1);
	}
	return (0);
}

static char	*try_segment(const char *start, char *cmd, const char **next)
{
	const char	*colon;
	size_t		len;
	char		dir[1024];
	char		*full_path;

	colon = ft_strchr(start, ':');
	if (!colon)
		colon = start + ft_strlen(start);
	len = colon - start;
	if (len >= sizeof(dir))
		len = sizeof(dir) - 1;
	ft_strncpy(dir, start, len);
	dir[len] = '\0';
	full_path = join_path(dir, cmd);
	if (full_path[0] != '\0' && access(full_path, X_OK | F_OK) == 0)
	{
		*next = colon;
		return (full_path);
	}
	free(full_path);
	*next = colon;
	return (NULL);
}

char	*search_command(char *cmd, t_envnode *envp)
{
	char		*path_env;
	const char	*next;
	char		*found;

	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_env = ft_getenv("$PATH", envp);
	if (!path_env)
		return (NULL);
	next = path_env;
	while (*next)
	{
		found = try_segment(next, cmd, &next);
		if (found != NULL)
		{
			return (free(path_env), found);
		}
		if (*next != 0)
			next++;
	}
	return (free(path_env), NULL);
}
