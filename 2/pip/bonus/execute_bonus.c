/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:43:17 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/28 19:26:00 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static void	set_before_adding_path(int *idx, char arr[], char *command)
{
	*idx = 0;
	arr[0] = '/';
	ft_strlcpy(arr + 1, command, ft_strlen(command) + 2);
}

static void	run_command(char **path, char **command)
{
	int		idx;
	int		exec_chk;
	char	slash_command[20];
	char	*file_dir;

	exec_chk = access(command[0], X_OK);
	if (!exec_chk)
		execve(command[0], command, NULL);
	else
	{
		set_before_adding_path(&idx, slash_command, command[0]);
		while (path[idx])
		{
			file_dir = ft_strjoin(path[idx], slash_command);
			if (!file_dir)
				perror("memory allocation failed");
			exec_chk = access(file_dir, X_OK);
			if (!exec_chk)
				execve(file_dir, command, NULL);
			free(file_dir);
			idx++;
		}
	}
	if (exec_chk)
		perror("command not found");
}

static void	free_all(char **strset)
{
	int	idx;

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
		perror("malloc() failed");
	command = ft_split(command_str, ' ');
	if (!command)
		perror("malloc() failed");
	run_command(path, command);
	free_all(path);
	free_all(command);
}
