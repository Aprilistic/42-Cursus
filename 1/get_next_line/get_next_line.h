/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:31:53 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/14 13:31:02 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif
