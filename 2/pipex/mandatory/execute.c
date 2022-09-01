/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:43:17 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/30 14:02:30 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **env)
{
	int		idx;
	char	*path_str;
	char	**path_set;

	idx = 0;
	while (env[idx])
	{
		if (!ft_strncmp(env[idx], "PATH=", 5))
			break ;
		idx++;
	}
	if (!env[idx])
		return (NULL);
	path_str = ft_strdup(env[idx] + 5);
	if (!path_str)
		return (NULL);
	path_set = ft_split(path_str, ':');
	free(path_str);
	if (!path_set)
		return (NULL);
	return (path_set);
}

static void	find_path_and_run_command(int *exec_chk, char **path,
	char **command, char **envp)
{
	int		idx;
	char	slash_command[42];
	char	*file_dir;

	idx = 0;
	slash_command[0] = '/';
	ft_strlcpy(slash_command + 1, command[0], ft_strlen(command[0]) + 2);
	while (path[idx])
	{
		file_dir = ft_strjoin(path[idx], slash_command);
		if (!file_dir)
		{
			perror("malloc() failed");
			return ;
		}
		*exec_chk = access(file_dir, X_OK);
		if (!(*exec_chk))
			execve(file_dir, command, envp);
		free(file_dir);
		idx++;
	}
}

static void	run_command(char **path, char **command, char **envp)
{
	int		exec_chk;

	exec_chk = access(command[0], X_OK);
	if (!exec_chk)
		execve(command[0], command, NULL);
	else
		find_path_and_run_command(&exec_chk, path, command, envp);
	if (exec_chk)
	{
		write(STDERR_FILENO, "command not found: ", 19);
		write(STDERR_FILENO, command[0], ft_strlen(command[0]));
		write(STDERR_FILENO, "\n", 1);
	}
}

static void	free_all(char **strset)
{
	int	idx;

	if (!strset)
		return ;
	idx = 0;
	while (strset[idx])
	{
		free(strset[idx]);
		idx++;
	}
	free(strset);
}

void	execute_command(char *command_str, char **envp)
{
	char	**path;
	char	**command;

	path = get_path(envp);
	if (!path)
	{
		perror("malloc() failed");
		return ;
	}
	command = ft_split(command_str, ' ');
	if (!command)
	{
		perror("malloc() failed");
		free_all(path);
		return ;
	}
	run_command(path, command, envp);
	free_all(path);
	free_all(command);
}
