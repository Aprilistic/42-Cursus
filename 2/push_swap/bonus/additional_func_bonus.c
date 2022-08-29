/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:24:49 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 15:02:49 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static long long	atoi_modified(const char *str)
{
	long long	ret;
	int			sign;
	size_t		checked_byte;

	ret = 0;
	sign = 1;
	checked_byte = 0;
	if (*str != '-' && (*str < '0' || '9' < *str))
		return (ERROR);
	if (*(str + checked_byte) == '-')
	{
		if (*(str + checked_byte) == '-')
			sign = -1;
		checked_byte++;
	}
	while ('0' <= *(str + checked_byte) && *(str + checked_byte) <= '9')
	{
		ret *= 10;
		ret += *(str + checked_byte) - '0';
		checked_byte++;
	}
	if (ret * sign < INTMIN || INTMAX < ret * sign)
		return (ERROR);
	return (ret * sign);
}

static int	duplicate_check(t_node **a, int value)
{
	int		node_num;
	int		idx;
	t_node	*cur;

	node_num = node_size(a);
	idx = 0;
	cur = *a;
	while (idx < node_num)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
		idx++;
	}
	return (0);
}

void	data_input(t_node **a, int argc, char **argv)
{
	int			idx;
	long long	value;
	t_node		*newnode;

	idx = 1;
	while (idx < argc)
	{
		value = atoi_modified(argv[idx]);
		if (value == (ERROR) || duplicate_check(a, value))
		{
			delete_node(a);
			write(1, "Error\n", 6);
			exit(1);
		}
		newnode = make_node(value);
		if (!newnode)
		{
			delete_node(a);
			write(1, "Error\n", 6);
			exit(1);
		}
		push(a, newnode);
		rotate(a);
		idx++;
	}
}

int	power(int base, int expo)
{
	int	opr_cnt;
	int	ret;

	ret = 1;
	opr_cnt = 0;
	while (opr_cnt < expo)
	{
		ret *= base;
		opr_cnt++;
	}
	return (ret);
}

int	get_depth(int total_size)
{
	int	depth;

	depth = 0;
	while (total_size > power(3, depth) / 3 * 4)
		depth++;
	return (depth);
}
