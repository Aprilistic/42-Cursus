/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:04 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/19 16:14:57 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//if there is any width or precision, those values are set to -1.

long long	get_flags(const char **fmt)
{
	long long		flags;
	register char	c;

	flags = 0;
	while (ft_strchr("#-+ 0", (int)**fmt))
	{
		c = **fmt;
		if (c == '#')
			flags |= SPECIAL;
		else if (c == '-')
			flags |= LEFT;
		else if (c == '+')
			flags |= PLUS;
		else if (c == ' ')
			flags |= SPACE;
		else if (c == '0')
			flags |= ZEROPAD;
		(*fmt)++;
	}
	return (flags);
}

int	get_width(const char **fmt, va_list args)
{
	int	width;

	width = 0;
	if ('1' <= **fmt && **fmt <= '9')
	{
		while (ft_isdigit(**fmt))
		{
			width *= 10;
			width += **fmt - '0';
			(*fmt)++;
		}
	}
	else if (**fmt == '*')
	{
		width = va_arg(args, int);
		(*fmt)++;
	}
	return (width);
}

int	get_precision(const char **fmt, va_list args)
{
	int	precision;

	if (**fmt != '.')
		return (-1);
	(*fmt)++;
	precision = 0;
	while (ft_isdigit(**fmt))
	{
		precision *= 10;
		precision += **fmt - '0';
		(*fmt)++;
	}
	if (**fmt == '*')
	{
		precision = va_arg(args, int);
		(*fmt)++;
	}
	return (precision);
}

void	get_length(const char **fmt)
{
	if (**fmt == 'l')
		(*fmt)++;
}
