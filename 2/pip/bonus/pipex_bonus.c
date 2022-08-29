/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:32:41 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/29 11:48:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child1_process(int pid, char *command, char **envp)
{
	if (pid == 0)
	{
		execute_command(command, envp);
	}
}

void	child2_process(int pid, char *command, char **envp)
{
	if (pid == 0)
	{
		execute_command(command, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid[2];
	int		fd[2][2];
	int		source;
	int		destination;
	int		idx;

	if (argc < 2)
		return (0);
	if (pipe(fd[0]) == -1 || pipe(fd[1]) == -1)
		perror("pipe() failed ");
	pid[0] = fork();
	if (pid[0] > 0)
		pid[1] = fork();
	child1_reroute(pid[0], fd);
	child2_reroute(pid[1], fd);
	idx = 1;
	if (!access(argv[idx], R_OK) && pid[0] && pid[1])
		source = open(argv[idx], O_RDONLY);
	parent_reroute(pid, fd);
	idx++;
	while (idx < argc - 1)
	{
		if ((idx % 2) == 0)
		{
			child2_process(pid[1], argv[idx], envp);
			//waitpid(pid[1], NULL, 0);
		}
		else
		{
			child1_process(pid[0], argv[idx], envp);
			//waitpid(pid[0], NULL, 0);
		}
		idx++;
	}
	//mush deal with pid, not considering heardoc
	destination = open(argv[idx], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	//close & pipe output
	return (0);
}
