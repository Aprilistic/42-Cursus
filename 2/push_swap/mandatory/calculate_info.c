/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:50:28 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/09 16:33:53 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//3^depth is current trangle num, idx is from lower node
static int	calculate_size(int size, int depth, int idx)
{
	int	max_idx;
	int	one_third;

	if (!depth)
		return (size);
	max_idx = power(3, depth);
	if ((size + 1) % 3 == 0)
		one_third = (size + 1) / 3;
	else
		one_third = size / 3;
	if (idx < max_idx / 3)
		return (calculate_size(one_third, depth - 1, idx));
	else if (idx < max_idx / 3 * 2)
		return (calculate_size(size - one_third * 2, depth - 1,
				idx - max_idx / 3));
	else
		return (calculate_size(one_third, depth - 1, idx - max_idx / 3 * 2));
}

int	calculate_sort_order(int idx)
{
	int	depth;
	int	mirror;
	int	diff;
	int	flip;

	flip = 0;
	while (idx > 2)
	{
		depth = 0;
		while (idx >= power(3, depth + 1))
			depth++;
		mirror = power(3, depth);
		diff = idx % mirror;
		idx = mirror - 1 - diff;
		flip++;
	}
	if ((idx && !(flip % 2)) || (!idx && (flip % 2)))
		return (0);
	return (1);
}

int	calculate_backtrack(int total_size, int max_depth, int cur_depth, int idx)
{
	int	ret;
	int	max_idx;

	if (cur_depth == max_depth - 1)
		return (calculate_size(total_size, max_depth - 1, idx));
	max_idx = power(3, cur_depth);
	ret = 0;
	ret += calculate_backtrack(total_size, max_depth, cur_depth + 1,
			idx + max_idx * 2);
	ret += calculate_backtrack(total_size, max_depth, cur_depth + 1,
			idx + max_idx);
	ret += calculate_backtrack(total_size, max_depth, cur_depth + 1, idx);
	return (ret);
}

t_info	calculate_info(int size, int depth, int idx)
{
	t_info	ret;
	int		max_depth;
	int		max_idx;

	max_depth = get_depth(size);
	max_idx = power(3, depth - 1);
	ret.another_bottom = calculate_backtrack(size, max_depth, depth,
			idx + max_idx * 2);
	ret.this_top = calculate_backtrack(size, max_depth, depth, idx + max_idx);
	ret.this_bottom = calculate_backtrack(size, max_depth, depth, idx);
	return (ret);
}

int	calculate_prepass_count(int total_size, int depth)
{
	int		max_idx;
	int		idx;
	int		ret;
	t_info	info;

	max_idx = power(3, depth - 1);
	idx = 0;
	ret = 0;
	while (idx < max_idx)
	{
		info = calculate_info(total_size, depth, idx);
		ret += info.another_bottom;
		idx++;
	}
	return (ret);
}
