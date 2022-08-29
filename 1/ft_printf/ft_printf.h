/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:26:57 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/20 10:46:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define MAXBUF		500		/* max buffer size */

# define ZEROPAD	1		/* pad with zero */
# define SIGN		2		/* unsigned/signed long */
# define PLUS		4		/* show plus */
# define SPACE		8		/* space if plus */
# define LEFT		16		/* left justified */
# define SMALL		32		/* Must be 32 == 0x20 */
# define SPECIAL	64		/* 0x */
# define HEX		128		/* hexadecimal */
# define NEG		256		/* negative num */
# define ZERO		512		/* zero num(special) */

typedef struct s_size
{
	int	width;
	int	precision;
}t_size;

//from ft_printf.c
int			ft_printf(const char *fmt, ...);
int			iprintf(const char *fmt, va_list args);
int			print_by_format(const char **fmt, va_list args);
int			print_by_specifier(const char **fmt, int flags,
				t_size wp, va_list args);
long long	update_flags(int flags, const char **fmt);

//from get_functions.c
long long	get_flags(const char **fmt);
int			get_width(const char **fmt, va_list args);
int			get_precision(const char **fmt, va_list args);
void		get_length(const char **fmt);

//from print_functions.c
int			print_num(int flags, t_size wp, va_list args);
int			print_addr(int flags, t_size wp, va_list args);
int			print_char(int flags, t_size wp, va_list args);
int			print_percent(int flags, t_size wp);
int			print_str(int flags, t_size wp, va_list args);

//from buffer_functions.c
char		*write_buffer(long long i, char buf[], int flags, t_size wp);
char		*write_buffer_addr(uintptr_t i, char buf[], int flags);
char		*handle_zero(char *p, char buf[], int flags, t_size wp);
char		*handle_sign_and_special(char *p, int flags);
int			print_buffer(char *p, char buf[], int flags, t_size wp);

//from additional_functions.c
char		*ft_strchr(const char *s, int c);
void		ft_putchar(char ch);
int			ft_isdigit(int ch);
int			ft_strlen(const char *s);

#endif
