/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:32:57 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/29 20:40:43 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_backup(char **backup, char *buff);
char	*free_all(char **ptr);
char	*separate_by_newline(char **backup);
char	*reached_end_of_file(char **backup);

char	*get_next_line(int fd)
{
	char		buff[(BUFFER_SIZE) + 1];
	static char	*backup;
	int			read_len;

	if (fd < 0 || (BUFFER_SIZE) <= 0)
		return (free_all(&backup));
	while (1)
	{
		if (ft_strchr_gnl(backup, '\n'))
			break ;
		ft_memset_gnl(buff, 0, (BUFFER_SIZE) + 1);
		read_len = read(fd, buff, (BUFFER_SIZE));
		if (read_len < 0)
			return (free_all(&backup));
		backup = update_backup(&backup, &buff[0]);
		if (!backup)
			return (free_all(&backup));
		if (read_len < (BUFFER_SIZE))
			break ;
	}
	if (ft_strchr_gnl(backup, '\n'))
		return (separate_by_newline(&backup));
	return (reached_end_of_file(&backup));
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

	backup_len = ft_strlen_gnl(*backup);
	buff_len = ft_strlen_gnl(buff);
	if (backup_len + buff_len == 0)
		return (free_all(backup));
	new_backup = ft_calloc_gnl(1, backup_len + buff_len + 1);
	if (!new_backup)
		return (free_all(backup));
	ft_strlcat_gnl(new_backup, *backup, backup_len + buff_len + 1);
	ft_strlcat_gnl(new_backup, buff, backup_len + buff_len + 1);
	free_all(backup);
	return (new_backup);
}

char	*separate_by_newline(char **backup)
{
	char	*newstr;
	char	*newline_occur_point;

	newline_occur_point = ft_strchr_gnl(*backup, '\n');
	newstr = ft_calloc_gnl(1, newline_occur_point - *backup + 2);
	if (!newstr)
		return (free_all(backup));
	ft_strlcat_gnl(newstr, *backup, newline_occur_point - *backup + 2);
	*backup[0] = 0;
	*backup = update_backup(backup, newline_occur_point + 1);
	return (newstr);
}

char	*reached_end_of_file(char **backup)
{
	char	*newstr;
	size_t	backup_len;

	backup_len = ft_strlen_gnl(*backup);
	if (!backup_len)
		return (0);
	newstr = ft_calloc_gnl(1, backup_len + 1);
	ft_strlcat_gnl(newstr, *backup, backup_len + 1);
	free_all(backup);
	return (newstr);
}
