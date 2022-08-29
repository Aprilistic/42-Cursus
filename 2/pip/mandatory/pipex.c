/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:32:41 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/28 14:46:19 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(int pid, int fd[], char **argv, char **envp)
{
	if (pid < 0)
	{
		perror("fork() failed");
		exit(1);
	}
	if (pid == 0)
	{
		if (access(argv[1], R_OK) < 0)
			return ;
		dup2(open(argv[1], O_RDONLY), STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execute_command(argv[2], envp);
	}
}

void	child2_process(int pid, int fd[], char **argv, char **envp)
{
	if (pid < 0)
	{
		perror("fork() failed ");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777), STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execute_command(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid[2];
	int		fd[2];

	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
		perror("pipe() failed ");
	pid[0] = fork();
	if (pid[0] > 0)
		pid[1] = fork();
	child1_process(pid[0], fd, argv, envp);
	child2_process(pid[1], fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
