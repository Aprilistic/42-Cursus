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
	return (len);
}

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

//prefix : "*_"
char	*index_string(char *prefix, int index)
{
	char	*indexed_string;
	int		required_length;
	
}
