/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:08:21 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/21 10:43:25 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	s_size;
	size_t	location;

	s_size = ft_strlen(s);
	location = 0;
	while (location <= s_size)
	{
		if (*(s + location) == (char)c)
			return ((char *)(s + location));
		location++;
	}
	return (0);
}

void	ft_putchar(char ch)
{
	unsigned char	c;

	c = (unsigned char)ch;
	write(1, &c, sizeof(c));
}

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

int	ft_isdigit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}
