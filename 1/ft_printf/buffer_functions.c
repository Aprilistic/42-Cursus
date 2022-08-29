/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:12:51 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/20 10:46:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//p is always set to empty address, it means right before last written address.
//LEFTPAD and ZEROPAD are not compatible, ZEROPAD WINS
char	*write_buffer(long long i, char buf[], int flags, t_size wp)
{
	static const char	digits[] = "0123456789ABCDEF";
	char				*p;
	int					base;

	base = 10;
	if (flags & HEX)
		base = 16;
	p = &buf[MAXBUF - 1];
	if (i == 0 && !(wp.precision == 0))
		*p-- = '0';
	while (i)
	{
		*p = digits[i % base];
		if (flags & SMALL && *p >= 'A')
			*p += 'a' - 'A';
		i /= base;
		p--;
	}
	p = handle_zero(p, buf, flags, wp);
	p = handle_sign_and_special(p, flags);
	return (p);
}

char	*write_buffer_addr(uintptr_t i, char buf[], int flags)
{
	static const char	digits[] = "0123456789ABCDEF";
	char				*p;
	int					base;

	base = 16;
	p = &buf[MAXBUF - 1];
	if (i == 0)
		*p-- = '0';
	while (i)
	{
		*p = digits[i % base];
		if (flags & SMALL && *p >= 'A')
			*p += 'a' - 'A';
		i /= base;
		p--;
	}
	return (p);
}

char	*handle_zero(char *p, char buf[], int flags, t_size wp)
{
	int	digit_size;
	int	total_size;

	digit_size = &buf[MAXBUF - 1] - p;
	while (digit_size++ < wp.precision)
			*p-- = '0';
	total_size = digit_size;
	if ((flags & SPECIAL) && !(flags & ZERO))
		total_size += 2;
	if ((flags & NEG) || (flags & PLUS) || (flags & SPACE))
		total_size++;
	if (!(flags & LEFT) && (flags & ZEROPAD) && wp.precision == -1)
		while (total_size++ < wp.width + 1)
			*p-- = '0';
	return (p);
}

char	*handle_sign_and_special(char *p, int flags)
{
	if ((flags & SPECIAL) && !(flags & ZERO) && (flags & SMALL))
		*p-- = 'x';
	else if ((flags & SPECIAL) && !(flags & ZERO))
		*p-- = 'X';
	if ((flags & SPECIAL) && !(flags & ZERO))
		*p-- = '0';
	if (flags & NEG)
		*p-- = '-';
	else if (flags & PLUS)
		*p-- = '+';
	else if (flags & SPACE)
		*p-- = ' ';
	return (p);
}

int	print_buffer(char *p, char buf[], int flags, t_size wp)
{
	int	length;

	length = &buf[MAXBUF - 1] - p;
	if (!(flags & LEFT))
		while (length++ < wp.width)
			ft_putchar(' ');
	while (p++ < &buf[MAXBUF - 1])
		ft_putchar(*p);
	if (flags & LEFT)
		while (length++ < wp.width)
			ft_putchar(' ');
	return (length);
}
