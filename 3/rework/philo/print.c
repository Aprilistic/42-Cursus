/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:52:15 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/17 20:38:21 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void	print_message(t_data *data, struct timeval *now, int philosopher_idx,
		int mode)
{
	int	timestamp;

	timestamp = get_time_difference_in_ms(&(data->start_time), now);
	if (mode == TAKEN)
		printf(YEL "%d %d has taken a fork\n" RESET, timestamp, philosopher_idx
			+ 1);
	else if (mode == EATING)
		printf(WHT "%d %d is eating\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == SLEEPING)
		printf(BLU "%d %d is sleeping\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == THINKING)
		printf(CYN "%d %d is thinking\n" RESET, timestamp, philosopher_idx + 1);
	else if (mode == DEAD)
		printf(RED "%d %d died\n" RESET, timestamp, philosopher_idx + 1);
}
