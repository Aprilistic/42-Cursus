/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefined_func_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:21:12 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 12:53:16 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stl_of_mine.h"

void	r(t_node **top, int a)
{
	if (!top || !(*top))
		return ;
	if ((*top)->next == *top)
		return ;
	rotate(top);
	write(1, "r", 1);
	if (a)
		write(1, "a\n", 2);
	else
		write(1, "b\n", 2);
}

void	rr(t_node **top, int a)
{
	if (!top || !(*top))
		return ;
	if ((*top)->next == *top)
		return ;
	reverse_rotate(top);
	write(1, "rr", 2);
	if (a)
		write(1, "a\n", 2);
	else
		write(1, "b\n", 2);
}

void	r_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rr_both(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
