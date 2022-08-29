/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:26:43 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/20 10:46:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;

	va_start(args, fmt);
	i = iprintf(fmt, args);
	va_end(args);
	return (i);
}

int	iprintf(const char *fmt, va_list args)
{
	int	length;

	length = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt++);
			length++;
		}
		else
			length += print_by_format(&fmt, args);
	}
	return (length);
}

int	print_by_format(const char **fmt, va_list args)
{
	long long	flags;
	t_size		wp;

	(*fmt)++;
	flags = get_flags(fmt);
	wp.width = get_width(fmt, args);
	wp.precision = get_precision(fmt, args);
	get_length(fmt);
	return (print_by_specifier(fmt, flags, wp, args));
}

long long	update_flags(int flags, const char **fmt)
{
	if (**fmt == 'x' || **fmt == 'X' || **fmt == 'p')
		flags |= HEX;
	if (**fmt == 'x' || **fmt == 'p')
		flags |= SMALL;
	if (**fmt == 'd' || **fmt == 'i')
		flags |= SIGN;
	return (flags);
}

int	print_by_specifier(const char **fmt, int flags,
	t_size wp, va_list args)
{
	int	length;

	length = 0;
	flags = update_flags(flags, fmt);
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u'
		|| **fmt == 'x' || **fmt == 'X')
		length += print_num(flags, wp, args);
	else if (**fmt == 'p')
		length += print_addr(flags, wp, args);
	else if (**fmt == 'c')
		length += print_char(flags, wp, args);
	else if (**fmt == '%')
		length += print_percent(flags, wp);
	else if (**fmt == 's')
		length += print_str(flags, wp, args);
	else if (**fmt)
	{
		ft_putchar(**fmt);
		length++;
	}
	(*fmt)++;
	return (length);
}
