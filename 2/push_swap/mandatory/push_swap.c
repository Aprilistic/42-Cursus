/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:41:54 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/12 17:42:01 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_check(t_node **a)
{
	t_node	*cur;
	int		a_size;
	int		idx;

	a_size = node_size(a);
	cur = *a;
	idx = 0;
	while (idx < a_size - 1)
	{
		if (cur->value > cur->next->value)
			return (0);
		idx++;
		cur = cur->next;
	}
	return (1);
}

void	push_swap(t_node **a, t_node **b)
{
	int	total_size;
	int	depth;

	if (sort_check(a))
		return ;
	total_size = node_size(a);
	if (total_size < 6)
	{
		small_num_sort(a, b);
		return ;
	}
	depth = get_depth(total_size);
	if (depth % 2 == 0)
		init_sort_a_to_b(a, b, --depth, 0);
	else
		init_sort_a_to_a(a, b, --depth, 1);
	while (depth)
	{
		if (depth % 2)
			merge_sort(b, a, depth, 1);
		else
			merge_sort(a, b, depth, 0);
		depth--;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = 0;
	b = 0;
	data_input(&a, argc, argv);
	push_swap(&a, &b);
	delete_node(&a);
	return (0);
}
