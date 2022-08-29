/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefined_func_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:21:12 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 12:49:21 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stl_of_mine_bonus.h"

void	r(t_node **top)
{
	if (!top || !(*top))
		return ;
	if ((*top)->next == *top)
		return ;
	rotate(top);
}

void	rr(t_node **top)
{
	if (!top || !(*top))
		return ;
	if ((*top)->next == *top)
		return ;
	reverse_rotate(top);
}

void	r_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

void	rr_both(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
