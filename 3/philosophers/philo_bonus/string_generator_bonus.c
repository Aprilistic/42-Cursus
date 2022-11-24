/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_generator_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:32:54 by jinheo            #+#    #+#             */
/*   Updated: 2022/11/23 21:42:49 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len++])
	{
	}
	return (--len);
}

static void ft_strcpy(char *src, char *dest)
{
	while (1)
	{
		*dest = *src;
		if (!*src)
			break;
		dest++;
		src++;
	}
}

static void	set_index_area(char *indexed_string, int index)
{
	int format_len;
	int idx;

	format_len = ft_strlen(indexed_string);
	idx = format_len + 8;
	printf("chk %d %s\n", format_len, indexed_string);
	indexed_string[format_len] = '_';
	printf("chk %d %s\n", format_len, indexed_string);
	while (idx > format_len)
	{
		indexed_string[idx] = index % 10 + '0';
		index /= 10;
		idx--;
	}
	indexed_string[format_len + 9] = 0;
}

//format : "*" 8-digits index
char	*index_string(char *format, int index)
{
	char *indexed_string;
	int	format_len;

	format_len = ft_strlen(format);
	indexed_string = (char *)malloc(format_len + 10);
	if (indexed_string == NULL)
	{
		write(STDERR_FILENO, "malloc() failed.\n", 17);
		return (NULL);
	}
	ft_strcpy(format, indexed_string);
	set_index_area(indexed_string, index);
	return (indexed_string);
}