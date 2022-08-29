/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:22:06 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 12:41:38 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stl_of_mine_bonus.h"

t_node	*make_node(int value)
{
	t_node	*newnode;

	newnode = (t_node *) malloc (sizeof(t_node));
	if (!newnode)
		return (0);
	newnode->value = value;
	return (newnode);
}

void	delete_node(t_node **top)
{
	int		node_count;
	int		opr_count;
	t_node	*cur;
	t_node	*target;

	node_count = node_size(top);
	opr_count = 0;
	cur = *top;
	while (opr_count < node_count)
	{
		target = cur;
		if (opr_count < node_count - 1)
			cur = cur->next;
		free(target);
		opr_count++;
	}
	*top = 0;
}

int	node_size(t_node **top)
{
	t_node	*start;
	t_node	*cur;
	int		count;

	start = *top;
	cur = start;
	if (!cur)
		return (0);
	count = 1;
	cur = cur->next;
	while (cur != start)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}
