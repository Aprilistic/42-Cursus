/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefined_func_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:23:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 12:54:02 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stl_of_mine_bonus.h"

void	p(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!from || !(*from))
		return ;
	tmp = pop(from);
	push(to, tmp);
}

void	s(t_node **top)
{
	if (!top || !(*top))
		return ;
	if ((*top)->next == *top)
		return ;
	swap(top);
}

void	s_both(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
