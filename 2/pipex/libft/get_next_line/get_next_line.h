/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:31:53 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/29 20:24:28 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 8

char	*get_next_line(int fd);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_memset_gnl(void *b, int c, size_t len);
void	*ft_calloc_gnl(size_t count, size_t size);

#endif
