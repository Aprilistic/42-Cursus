/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_of_mine_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:12:50 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/10 16:51:28 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_OF_MINE_BONUS_H
# define STL_OF_MINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

//basic_func.c
void	push(t_node **top, t_node *newnode);
t_node	*pop(t_node **top);
void	rotate(t_node **top);
void	reverse_rotate(t_node **top);
void	swap(t_node	**top);
t_node	*make_node(int value);
void	delete_node(t_node **top);
int		node_size(t_node **top);

//redefined_func.c
void	r(t_node **top);
void	rr(t_node **top);
void	r_both(t_node **a, t_node **b);
void	rr_both(t_node **a, t_node **b);
void	p(t_node **from, t_node **to);
void	s(t_node **top);
void	s_both(t_node **a, t_node **b);

#endif
