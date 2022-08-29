/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:06:48 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 15:04:10 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stl/stl_of_mine_bonus.h"

# define BUFFER_SIZE 1
# define ERROR (long long)1e13
# define INTMAX (long long)2147483647
# define INTMIN (long long)-2147483648

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	data_input(t_node **a, int argc, char **argv);

#endif
