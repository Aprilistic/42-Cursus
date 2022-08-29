/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_num_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:28:59 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/10 12:32:23 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_node **from);
static void	sort_4_5(t_node **from, t_node **to);

void	small_num_sort(t_node **from, t_node **to)
{
	int	total_size;

	total_size = node_size(from);
	if (total_size < 2)
		return ;
	else if (total_size == 2)
	{
		if ((*from)->value > (*from)->next->value)
			s(from, 1);
	}
	else if (total_size == 3)
		sort_3(from);
	else
		sort_4_5(from, to);
}

static void	sort_3(t_node **from)
{
	if ((*from)->value > (*from)->next->value
		&& (*from)->value > (*from)->prev->value)
	{
		r(from, 1);
		if ((*from)->value > (*from)->next->value)
			s(from, 1);
	}
	else if ((*from)->prev->value > (*from)->value
		&& (*from)->prev->value > (*from)->next->value)
	{
		if ((*from)->value > (*from)->next->value)
			s(from, 1);
	}
	else
	{
		rr(from, 1);
		if ((*from)->value > (*from)->next->value)
			s(from, 1);
	}
}

static void	sort_4_5(t_node **from, t_node **to)
{
	t_info	tmp;

	tmp.this_top = 1;
	tmp.this_bottom = 0;
	tmp.another_bottom = 3;
	if (node_size(from) == 5)
	{
		p(from, to, 0);
		tmp.this_top = 2;
	}
	p(from, to, 0);
	if ((*to)->value < (*to)->next->value)
		s(to, 0);
	sort_3(from);
	merge_sort_ascend(to, from, tmp, 1);
}
