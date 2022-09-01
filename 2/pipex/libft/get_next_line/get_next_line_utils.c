/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:41:31 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/29 20:33:23 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (*(str + length))
		length++;
	return (length);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;
	size_t	appendable_size;
	char	*ptr;

	s_len = ft_strlen_gnl(src);
	d_len = ft_strlen_gnl(dst);
	if (d_len > dstsize)
		return (s_len + dstsize);
	appendable_size = 0;
	if (d_len + 1 < dstsize)
		appendable_size = dstsize - 1 - d_len;
	ptr = dst + d_len;
	idx = 0;
	while (idx < appendable_size && idx < s_len)
	{
		*(ptr + idx) = *(src + idx);
		idx++;
	}
	*(ptr + idx) = 0;
	if (d_len > dstsize)
		return (s_len + dstsize);
	return (d_len + s_len);
}

void	*ft_memset_gnl(void *b, int c, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		*(unsigned char *)(b + count) = (unsigned char)c;
		count++;
	}
	return (b);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*p;
	size_t	*checked_byte;

	p = (void *) malloc (count * size);
	if (!p)
		return (0);
	checked_byte = 0;
	ft_memset_gnl(p, 0, count * size);
	return (p);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	s_size;
	size_t	location;

	if (!s)
		return (0);
	s_size = ft_strlen_gnl(s);
	location = 0;
	while (location <= s_size)
	{
		if (*(s + location) == (char)c)
			return ((char *)(s + location));
		location++;
	}
	return (0);
}
