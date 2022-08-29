/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:07:59 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/10 14:50:49 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//3^depth is triangle num to be made
static void	init_sort_ascend(t_node **from, t_node **to, int size, int a);
static void	init_sort_ascend1(t_node **from, t_node **to, int size, int a);
static void	init_sort_descend(t_node **from, t_node **to, int size, int a);
static void	init_sort_descend1(t_node **from, t_node **to, int size, int a);

void	init_sort_a_to_b(t_node **from, t_node **to, int depth, int a)
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
		if (order)
			init_sort_ascend(from, to, size, a);
		else
			init_sort_descend(from, to, size, a);
		idx++;
	}
}

static void	init_sort_ascend(t_node **from, t_node **to, int size, int a)
{
	if (size == 1)
		p(from, to, a);
	else if (size == 2)
	{
		if ((*from)->value < (*from)->next->value)
			s(from, !a);
		p(from, to, a);
		p(from, to, a);
	}
	else if (size == 3 || size == 4)
		init_sort_ascend1(from, to, size, a);
}

static void	init_sort_ascend1(t_node **from, t_node **to, int size, int a)
{
	t_info	tmp;

	tmp.another_bottom = 1;
	tmp.this_top = 2;
	if (size == 3)
		tmp.this_top = 1;
	tmp.this_bottom = 1;
	p(from, to, a);
	r(to, a);
	if (size == 4 && (*from)->value < (*from)->next->value)
		s(from, !a);
	merge_sort_ascend(from, to, tmp, a);
}

static void	init_sort_descend(t_node **from, t_node **to, int size, int a)
{
	if (size == 1)
		p(from, to, a);
	else if (size == 2)
	{
		if ((*from)->value > (*from)->next->value)
			s(from, !a);
		p(from, to, a);
		p(from, to, a);
	}
	else if (size == 3 || size == 4)
		init_sort_descend1(from, to, size, a);
}

static void	init_sort_descend1(t_node **from, t_node **to, int size, int a)
{
	t_info	tmp;

	tmp.another_bottom = 1;
	tmp.this_top = 2;
	if (size == 3)
		tmp.this_top = 1;
	tmp.this_bottom = 1;
	p(from, to, a);
	r(to, a);
	if (size == 4 && (*from)->value > (*from)->next->value)
		s(from, !a);
	merge_sort_descend(from, to, tmp, a);
}
