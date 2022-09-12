/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:23:59 by jinheo            #+#    #+#             */
/*   Updated: 2022/09/12 15:25:53 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rule	data;

	if (!parse_argv(&data, argc, argv))
	{
		write(STDERR_FILENO, "Invalid input arguments.\n", 25);
		return (0);
	}
	lets_eat_think_sleep(&data);
	return (0);
}
