/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:10:15 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/18 20:24:36 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int flags, t_size wp, va_list args)
{
	char		buf[MAXBUF];
	char		*p;
	long long	i;
	int			length;

	if (flags & SIGN)
		i = va_arg(args, int);
	else
		i = va_arg(args, unsigned int);
	if (i < 0)
	{
		flags |= NEG;
		i *= -1;
	}
	else if (i == 0)
		flags |= ZERO;
	p = write_buffer(i, buf, flags, wp);
	length = print_buffer(p, buf, flags, wp);
	return (length - 1);
}

int	print_addr(int flags, t_size wp, va_list args)
{
	char		buf[MAXBUF];
	char		*p;
	int			length;
	uintptr_t	addr;

	addr = (uintptr_t)va_arg(args, void *);
	p = write_buffer_addr(addr, buf, flags);
	*p-- = 'x';
	*p-- = '0';
	length = print_buffer(p, buf, flags, wp);
	return (length - 1);
}

int	print_char(int flags, t_size wp, va_list args)
{
	unsigned char	ch;
	int				length;

	length = 1;
	ch = (unsigned char)va_arg(args, int);
	if (!(flags & LEFT) && (flags & ZEROPAD))
		while (length++ < wp.width)
			ft_putchar('0');
	if (!(flags & LEFT))
		while (length++ < wp.width)
			ft_putchar(' ');
	ft_putchar(ch);
	if (flags & LEFT)
		while (length++ < wp.width)
			ft_putchar(' ');
	return (length - 1);
}

int	print_percent(int flags, t_size wp)
{
	int				length;

	length = 1;
	if (!(flags & LEFT) && (flags & ZEROPAD))
		while (length++ < wp.width)
			ft_putchar('0');
	if (!(flags & LEFT))
		while (length++ < wp.width)
			ft_putchar(' ');
	ft_putchar('%');
	if (flags & LEFT)
		while (length++ < wp.width)
			ft_putchar(' ');
	return (length - 1);
}

int	print_str(int flags, t_size wp, va_list args)
{
	char	*str;
	int		length;
	int		idx;
	int		tmp;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (wp.precision != -1 && wp.precision < length)
		length = wp.precision;
	idx = length;
	if (!(flags & LEFT))
		while (length++ < wp.width)
			ft_putchar(' ');
	tmp = 0;
	while (tmp < idx)
		ft_putchar(str[tmp++]);
	if (flags & LEFT)
		while (length++ < wp.width)
			ft_putchar(' ');
	return (length - 1);
}
