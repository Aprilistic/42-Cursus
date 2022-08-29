/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reroute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:21:10 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/29 11:47:50 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

//child 2 -> child 1 : pipe 0
//child 1 -> child 2 : pipe 1

void	child1_reroute(int pid, int fd[][2])
{
	if (pid < 0)
	{
		perror("fork() failed");
		exit(1);
	}
	else if (pid == 0)
	{
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[1][1]);
		close(fd[1][0]);
	}
}

void	child2_reroute(int pid, int fd[][2])
{
	if (pid < 0)
	{
		perror("fork() failed ");
		exit(1);
	}
	else if (pid == 0)
	{
		dup2(fd[1][0], STDIN_FILENO);
		close(fd[1][0]);
		close(fd[1][1]);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][1]);
		close(fd[0][0]);
	}
}

void	parent_reroute(int pid[], int fd[][2])
{
	if (pid[0] && pid[1])
	{
		dup2(fd[0][1], STDOUT_FILENO);
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
	}
}
