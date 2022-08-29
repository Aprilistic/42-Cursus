/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefined_func_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:23:09 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 12:53:54 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stl_of_mine.h"

void	p(t_node **from, t_node **to, int a)
{
	t_node	*tmp;

	if (!from || !(*from))
		return ;
	tmp = pop(from);
	push(to, tmp);
	write(1, "p", 1);
	if (a)
		write(1, "a\n", 2);
	else
		write(1, "b\n", 2);
}

void	s(t_node **top, int a)
{
	if (!top || !(*top))
		return ;
	if ((*top)->next == *top)
		return ;
	swap(top);
	write(1, "s", 1);
	if (a)
		write(1, "a\n", 2);
	else
		write(1, "b\n", 2);
}

void	s_both(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
