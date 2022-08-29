/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:53:11 by jinheo            #+#    #+#             */
/*   Updated: 2022/08/11 15:04:20 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stl/stl_of_mine.h"

# define ERROR (long long)1e13
# define INTMAX (long long)2147483647
# define INTMIN (long long)-2147483648

typedef struct s_info
{
	long long	another_bottom;
	long long	this_top;
	long long	this_bottom;
}t_info;

//additional_func.c
void		data_input(t_node **a, int argc, char **argv);
int			power(int base, int expo);
int			get_depth(int total_size);
//calculate_info.c
int			calculate_sort_order(int idx);
t_info		calculate_info(int size, int depth, int idx);
int			calculate_backtrack(int total_size, int max_depth,
				int cur_depth, int idx);
int			calculate_prepass_count(int total_size, int depth);
//small_num_sort.c
void		small_num_sort(t_node **from, t_node **to);
//init_sort_func.c
void		init_sort_a_to_b(t_node **from, t_node **to, int depth, int a);
void		init_sort_a_to_a(t_node **from, t_node **to, int size, int a);
//merge_sort_func.c
void		merge_sort(t_node **from, t_node **to, int depth, int a);
void		merge_sort_ascend(t_node **from, t_node **to, t_info info, int a);
void		merge_sort_descend(t_node **from, t_node **to, t_info info, int a);

#endif
