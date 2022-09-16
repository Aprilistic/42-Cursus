/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:54:17 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/16 18:27:45 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//consider about proper name

void	monitor_routine(t_philosopher *thread)
{
	while (1)
	{
		if (now() - (*thread).hungry_since > overtime())
			status() = DEAD;
			break;
			//implement about returning value or signaling to waiter like something
	}
}

//consider split routine into several files
void	waiter_routine(void)
{
	int turn = 1;
	while (1)
	{
		
	}
}
