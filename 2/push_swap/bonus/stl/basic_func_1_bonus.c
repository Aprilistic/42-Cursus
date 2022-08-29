/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:55:30 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 12:55:28 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stl_of_mine_bonus.h"

void	push(t_node **top, t_node *newnode)
{
	if (!newnode)
		return ;
	if (!(*top))
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		*top = newnode;
		return ;
	}
	newnode->prev = (*top)->prev;
	newnode->next = *top;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	*top = newnode;
}

t_node	*pop(t_node **top)
{
	t_node	*target;

	if (!(*top) || !top)
		return (0);
	target = *top;
	if (target->next == *top)
	{
		*top = 0;
		return (target);
	}
	*top = (*top)->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	return (target);
}

void	rotate(t_node **top)
{
	if (!(*top) || !top)
		return ;
	(*top) = (*top)->next;
}

void	reverse_rotate(t_node **top)
{
	if (!(*top) || !top)
		return ;
	(*top) = (*top)->prev;
}

void	swap(t_node	**top)
{
	t_node	*tmp;

	if (!(*top) || !top)
		return ;
	tmp = pop(top);
	rotate(top);
	push(top, tmp);
	reverse_rotate(top);
}
