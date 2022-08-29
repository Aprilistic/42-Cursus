/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:31:45 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/29 11:39:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	execute_command(char *command, char **envp);

void	child1_reroute(int pid, int fd[][2]);
void	child2_reroute(int pid, int fd[][2]);
void	parent_reroute(int pid[], int fd[][2]);

#endif
