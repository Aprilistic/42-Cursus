/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:32:41 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/01 19:34:48 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	hear_doc(char *end)
{
	int		fd[2];
	int		pid;
	char	*getline;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			write(STDOUT_FILENO, "pipe heardoc> ", ft_strlen("pipe heardoc> "));
			getline = get_next_line(STDIN_FILENO);
			if (!ft_strncmp(end, getline, (size_t)ft_strlen(end)))
				break ;
			write(fd[1], getline, ft_strlen(getline));
			free(getline);
		}
		exit(0);
	}
	waitpid(pid, NULL, 0);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
}

void	open_file(char *infile, char **envp)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (access(infile, R_OK) < 0)
		{
			write(STDERR_FILENO, "Can't open file: ", 17);
			write(STDERR_FILENO, infile, ft_strlen(infile));
			write(STDERR_FILENO, "\n", 1);
			exit(0);
		}
		dup2(open(infile, O_RDONLY), STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execute_command("cat", envp);
		exit(0);
	}
	waitpid(pid, &status, WNOHANG);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
}

void	run_command(char **argv, char **envp, int idx)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		execute_command(argv[idx], envp);
		exit(0);
	}
	waitpid(pid, &status, WNOHANG);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
}

void	close_file(char *outfile, char **envp, int append)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (!access(outfile, W_OK) || (access(outfile, F_OK) == -1))
		{
			if (append)
				dup2(open(outfile, O_WRONLY | O_APPEND | O_CREAT, 0777),
					STDOUT_FILENO);
			else
				dup2(open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777),
					STDOUT_FILENO);
			execute_command("cat", envp);
		}
		else
			perror("");
		exit(0);
	}
	waitpid(pid, &status, WNOHANG);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	idx;
	int	append;

	if (argc < 3 || (argc < 4 && !ft_strcmp("hear_doc", argv[1])))
	{
		write(STDOUT_FILENO, "Invalid input parameters\n",
			ft_strlen("Invalid input parameters\n"));
		return (0);
	}
	append = 0;
	idx = 1;
	if (!ft_strcmp("hear_doc", argv[idx]))
	{
		append = 1;
		idx++;
		hear_doc(argv[idx]);
		idx++;
	}
	else
		open_file(argv[idx++], envp);
	while (idx < argc - 1)
		run_command(argv, envp, idx++);
	close_file(argv[idx], envp, append);
	return (0);
}
