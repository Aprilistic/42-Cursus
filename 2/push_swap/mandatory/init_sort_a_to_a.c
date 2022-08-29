/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort_a_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:15:28 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/12 20:28:08 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_sort_ascend(t_node **from, t_node **to, int size, int a);
static void	init_sort_ascend1(t_node **from, t_node **to, int a);
static void	init_sort_descend(t_node **from, t_node **to, int size, int a);
static void	init_sort_descend1(t_node **from, t_node **to, int a);

//from means a in this function.
void	init_sort_a_to_a(t_node **from, t_node **to, int depth, int a)
{
	int	total_size;
	int	size;
	int	order;
	int	max_idx;
	int	idx;

	total_size = node_size(from);
	max_idx = power(3, depth);
	idx = 0;
	while (idx < max_idx)
	{
		size = calculate_backtrack(total_size,
				get_depth(total_size), depth, idx);
		order = calculate_sort_order(idx);
		if (!size)
		{
			idx++;
			continue ;
		}
		if (order)
			init_sort_ascend(from, to, size, a);
		else
			init_sort_descend(from, to, size, a);
		idx++;
	}
}

static void	init_sort_ascend(t_node **from, t_node **to, int size, int a)
{
	rr(from, a);
	if (size == 2 || size == 3)
	{
		rr(from, a);
		if ((*from)->value > (*from)->next->value)
			s(from, a);
		if (size == 3)
		{
			rr(from, a);
			if ((*from)->value > (*from)->next->value
				&& (*from)->value < (*from)->next->next->value)
				s(from, a);
			else if ((*from)->value > (*from)->next->value
				&& (*from)->value > (*from)->next->next->value)
			{
				s(from, a);
				r(from, a);
				s(from, a);
				rr(from, a);
			}
		}
	}
	if (size == 4)
		init_sort_ascend1(from, to, a);
}

static void	init_sort_ascend1(t_node **from, t_node **to, int a)
{
	t_info	tmp;

	tmp.another_bottom = 1;
	tmp.this_top = 2;
	tmp.this_bottom = 1;
	rr(from, a);
	rr(from, a);
	p(from, to, !a);
	p(from, to, !a);
	p(from, to, !a);
	if ((*to)->value < (*to)->next->value)
		s(to, !a);
	merge_sort_ascend(to, from, tmp, a);
}

static void	init_sort_descend(t_node **from, t_node **to, int size, int a)
{
	rr(from, a);
	if (size == 2 || size == 3)
	{
		rr(from, a);
		if ((*from)->value < (*from)->next->value)
			s(from, a);
		if (size == 3)
		{
			rr(from, a);
			if ((*from)->value < (*from)->next->value
				&& (*from)->value > (*from)->next->next->value)
				s(from, a);
			else if ((*from)->value < (*from)->next->value
				&& (*from)->value < (*from)->next->next->value)
			{
				s(from, a);
				r(from, a);
				s(from, a);
				rr(from, a);
			}
		}
	}
	if (size == 4)
		init_sort_descend1(from, to, a);
}

static void	init_sort_descend1(t_node **from, t_node **to, int a)
{
	t_info	tmp;

	tmp.another_bottom = 1;
	tmp.this_top = 2;
	tmp.this_bottom = 1;
	rr(from, a);
	rr(from, a);
	p(from, to, !a);
	p(from, to, !a);
	p(from, to, !a);
	if ((*to)->value > (*to)->next->value)
		s(to, !a);
	merge_sort_descend(to, from, tmp, a);
}
