/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:26:24 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/14 14:49:29 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_backup(char **backup, char *buff);
char	*free_all(char **ptr);
char	*separate_by_newline(char **backup);
char	*reached_end_of_file(char **backup);

char	*get_next_line(int fd)
{
	char		buff[(BUFFER_SIZE) + 1];
	static char	*backup[10241];
	int			read_len;

	if (fd < 0 || (BUFFER_SIZE) <= 0)
		return (free_all(&backup[fd]));
	while (1)
	{
		if (ft_strchr(backup[fd], '\n'))
			break ;
		ft_memset(buff, 0, (BUFFER_SIZE) + 1);
		read_len = read (fd, buff, (BUFFER_SIZE));
		if (read_len < 0)
			return (free_all(&backup[fd]));
		backup[fd] = update_backup(&backup[fd], &buff[0]);
		if (!backup[fd])
			return (free_all(&backup[fd]));
		if (read_len < (BUFFER_SIZE))
			break ;
	}
	if (ft_strchr(backup[fd], '\n'))
		return (separate_by_newline(&backup[fd]));
	return (reached_end_of_file(&backup[fd]));
}

char	*free_all(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = 0;
	return (0);
}

char	*update_backup(char **backup, char *buff)
{
	char	*new_backup;
	size_t	backup_len;
	size_t	buff_len;

	backup_len = ft_strlen(*backup);
	buff_len = ft_strlen(buff);
	if (backup_len + buff_len == 0)
		return (free_all(backup));
	new_backup = ft_calloc(1, backup_len + buff_len + 1);
	if (!new_backup)
		return (free_all(backup));
	ft_strlcat(new_backup, *backup, backup_len + buff_len + 1);
	ft_strlcat(new_backup, buff, backup_len + buff_len + 1);
	free_all(backup);
	return (new_backup);
}

char	*separate_by_newline(char **backup)
{
	char	*newstr;
	char	*newline_occur_point;

	newline_occur_point = ft_strchr(*backup, '\n');
	newstr = ft_calloc(1, newline_occur_point - *backup + 2);
	if (!newstr)
		return (free_all(backup));
	ft_strlcat(newstr, *backup, newline_occur_point - *backup + 2);
	*backup[0] = 0;
	*backup = update_backup(backup, newline_occur_point + 1);
	return (newstr);
}

char	*reached_end_of_file(char **backup)
{
	char	*newstr;
	size_t	backup_len;

	backup_len = ft_strlen(*backup);
	if (!backup_len)
		return (0);
	newstr = ft_calloc(1, backup_len + 1);
	ft_strlcat(newstr, *backup, backup_len + 1);
	free_all(backup);
	return (newstr);
}
