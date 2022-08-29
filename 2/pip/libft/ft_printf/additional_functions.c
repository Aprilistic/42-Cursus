/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:08:21 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/28 17:37:39 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr_2(const char *s, int c)
{
	size_t	s_size;
	size_t	location;

	s_size = ft_strlen_2(s);
	location = 0;
	while (location <= s_size)
	{
		if (*(s + location) == (char)c)
			return ((char *)(s + location));
		location++;
	}
	return (0);
}

void	ft_putchar_2(char ch)
{
	unsigned char	c;

	c = (unsigned char)ch;
	write(1, &c, sizeof(c));
}

int	ft_strlen_2(const char *s)
{
	int	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

int	ft_isdigit_2(int ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}
