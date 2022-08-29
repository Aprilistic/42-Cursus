/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:06:32 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/12 17:44:42 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	error_occur(t_node **a, t_node **b)
{
	char	*gnl_return;

	while (1)
	{
		gnl_return = get_next_line(0);
		if (!gnl_return)
			break ;
		free(gnl_return);
	}
	delete_node(a);
	delete_node(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 == 0 && *s2 == 0)
			return (0);
		else if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
}

static void	simulate(t_node **a, t_node **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		p(b, a);
	else if (!ft_strcmp(cmd, "pb\n"))
		p(a, b);
	else if (!ft_strcmp(cmd, "sa\n"))
		s(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		s(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		s_both(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		r(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		r(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		r_both(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		rr(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rr(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rr_both(a, b);
	else
		error_occur(a, b);
}

static int	sort_check(t_node **a, t_node **b)
{
	t_node	*cur;
	int		a_size;
	int		idx;

	if (node_size(b))
		return (0);
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

int	main(int argc, char **argv)
{
	char	*cmd;
	t_node	*a;
	t_node	*b;

	if (argc == 1)
		return (0);
	a = 0;
	b = 0;
	data_input(&a, argc, argv);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		simulate(&a, &b, cmd);
		free(cmd);
		cmd = 0;
	}
	if (sort_check(&a, &b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_node(&a);
	delete_node(&b);
	return (0);
}
