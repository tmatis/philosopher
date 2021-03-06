/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:23:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/04 21:08:50 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_is_dead(t_philo *philo)
{
	return (get_relative_time(philo->manager->start_time) - philo->last_meal
		>= philo->manager->config.time_to_die);
}

void	dine(t_philo *philo)
{
	while (!stop_condition(philo))
	{
		if (philo->action == ACTION_EATING)
			action_eat(philo);
		else if (philo->action == ACTION_SLEEPING)
			action_sleep(philo);
		else if (philo->action == ACTION_THINKING)
			action_think(philo);
	}
	if (philo_is_dead(philo))
		write_status("died", philo);
}

void	*philo_routine(t_philo *philo)
{
	int		state;

	while (1)
	{
		state = manager_get_runstate(philo->manager);
		if ((!(philo->philo_id % 2) && state == RUN_EVEN) || state == RUN_ALL)
		{
			dine(philo);
			return (NULL);
		}
		usleep(PERF_DELAY);
	}
	return (NULL);
}
