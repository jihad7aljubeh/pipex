/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:00:00 by jihad             #+#    #+#             */
/*   Updated: 2025/12/15 20:28:51 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_path(char **paths, char *cmd)
{
	char	*tmp_path;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		tmp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*results;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			results = check_path(paths, cmd);
			free_split(paths);
			return (results);
		}
		i++;
	}
	return (NULL);
}

static void	cmd_not_found(char **cmd)
{
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_split(cmd);
	exit(127);
}

void	execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (!argv || !argv[0])
		exit(127);
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		free_split(cmd);
		exit(127);
	}
	path = find_path(cmd[0], envp);
	if (path == NULL)
		cmd_not_found(cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_split(cmd);
		perror("execve");
		exit(126);
	}
}
