/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:05:05 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/15 20:51:16 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	delete_data(t_data *data)
{
	if (data->philosophers)
		free(data->philosophers);
	if (data->monitors)
		free(data->monitors);
	if (data->waiter)
		free(data->waiter);
	if (data->forks)
		free(data->forks);
}
