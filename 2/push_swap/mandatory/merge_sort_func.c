/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:46:47 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/09 21:20:09 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//3^(depth - 1) is number to be merged
void		merge_sort_ascend(t_node **from, t_node **to, t_info info, int a);
void		merge_sort_descend(t_node **from, t_node **to, t_info info, int a);
static int	find_largest_number(t_node **from, t_node **to, t_info info);
static int	find_smallest_number(t_node **from, t_node **to, t_info info);

void	merge_sort(t_node **from, t_node **to, int depth, int a)
{
	int		total_size;
	t_info	info;
	int		max_idx;
	int		prepass_count;
	int		idx;

	total_size = node_size(from);
	prepass_count = calculate_prepass_count(total_size, depth);
	idx = 0;
	while (idx++ < prepass_count)
		p(from, to, a);
	max_idx = power(3, depth - 1);
	idx = 0;
	while (idx < max_idx)
	{
		info = calculate_info(total_size, depth, idx);
		if (calculate_sort_order(idx))
			merge_sort_ascend(from, to, info, a);
		else
			merge_sort_descend(from, to, info, a);
		idx++;
	}
}

void	merge_sort_ascend(t_node **from, t_node **to, t_info info, int a)
{
	int	node_idx;

	while (info.another_bottom || info.this_top || info.this_bottom)
	{
		node_idx = find_largest_number(from, to, info);
		if (node_idx == 1)
		{
			rr(to, a);
			info.another_bottom--;
		}
		else if (node_idx == 2)
		{
			p(from, to, a);
			info.this_top--;
		}
		else if (node_idx == 3)
		{
			rr(from, !a);
			p(from, to, a);
			info.this_bottom--;
		}
	}
}

void	merge_sort_descend(t_node **from, t_node **to, t_info info, int a)
{
	int	node_idx;

	while (info.another_bottom || info.this_top || info.this_bottom)
	{
		node_idx = find_smallest_number(from, to, info);
		if (node_idx == 1)
		{
			rr(to, a);
			info.another_bottom--;
		}
		else if (node_idx == 2)
		{
			p(from, to, a);
			info.this_top--;
		}
		else if (node_idx == 3)
		{
			rr(from, !a);
			p(from, to, a);
			info.this_bottom--;
		}
	}
}

static int	find_largest_number(t_node **from, t_node **to, t_info info)
{
	long long	another_bottom;
	long long	this_top;
	long long	this_bottom;

	another_bottom = -ERROR;
	this_top = -ERROR;
	this_bottom = -ERROR;
	if (info.another_bottom)
		another_bottom = (*to)->prev->value;
	if (info.this_top)
		this_top = (*from)->value;
	if (info.this_bottom)
		this_bottom = (*from)->prev->value;
	if (another_bottom != -ERROR && another_bottom > this_top
		&& another_bottom > this_bottom)
		return (1);
	else if (this_top != -ERROR && this_top > another_bottom
		&& this_top > this_bottom)
		return (2);
	else if (this_bottom != -ERROR && this_bottom > another_bottom
		&& this_bottom > this_top)
		return (3);
	return (0);
}

static int	find_smallest_number(t_node **from, t_node **to, t_info info)
{
	long long	another_bottom;
	long long	this_top;
	long long	this_bottom;

	another_bottom = ERROR;
	this_top = ERROR;
	this_bottom = ERROR;
	if (info.another_bottom)
		another_bottom = (*to)->prev->value;
	if (info.this_top)
		this_top = (*from)->value;
	if (info.this_bottom)
		this_bottom = (*from)->prev->value;
	if (another_bottom != ERROR && another_bottom < this_top
		&& another_bottom < this_bottom)
		return (1);
	else if (this_top != ERROR && this_top < another_bottom
		&& this_top < this_bottom)
		return (2);
	else if (this_bottom != ERROR && this_bottom < another_bottom
		&& this_bottom < this_top)
		return (3);
	return (0);
}
