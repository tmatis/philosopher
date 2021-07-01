/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:23:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/01 12:08:20 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		philo_is_dead(t_philo *philo)
{
	return (get_relative_time(philo->manager->start_time) - philo->last_meal
		>= philo->manager->config.time_to_die);
}

int	stop_condition(t_philo *philo)
{
	return (philo_is_dead(philo)
		|| manager_get_runstate(philo->manager) == RUN_STOP);
}

int	is_counter_reached(t_timems target, t_timems relative_start)
{
	return (get_relative_time(relative_start) >= target);
}

void	action_eat(t_philo *philo)
{
	t_timems	start;

	while (!stop_condition(philo) && take_forks(philo))
	{
		usleep(100);
		//printf("cannot take fork\n");
	}	
	if (stop_condition(philo))
		return ;
	philo->last_meal = get_relative_time(philo->manager->start_time);
	printf("%lli %i is eating\n", get_relative_time(philo->manager->start_time), philo->philo_id);
	start = get_actual_time();
	while (!stop_condition(philo)
		&& !is_counter_reached(philo->manager->config.time_to_eat, start))
		usleep(100);
	drop_forks(philo);
	philo->action = ACTION_SLEEPING;
}

void	action_sleep(t_philo *philo)
{
	t_timems	start;

	start = get_actual_time();
	printf("%lli %i is sleeping\n", get_relative_time(philo->manager->start_time), philo->philo_id);
	while (!stop_condition(philo)
		&& !is_counter_reached(philo->manager->config.time_to_sleep, start))
		usleep(100);
	philo->action = ACTION_THINKING;
}

void	action_think(t_philo *philo)
{
	printf("%lli %i is thinking\n", get_relative_time(philo->manager->start_time), philo->philo_id);
	philo->action = ACTION_EATING;
}

void	dine(t_philo *philo)
{
	while (manager_get_runstate(philo->manager) != RUN_STOP
			&& !philo_is_dead(philo))
	{
		if (philo->action == ACTION_EATING)
			action_eat(philo);
		if (philo->action == ACTION_SLEEPING)
			action_sleep(philo);
		if (philo->action == ACTION_THINKING)
			action_think(philo);
	}
	if (philo_is_dead(philo))
	{
		printf("%lli %i died\n", get_relative_time(philo->manager->start_time), philo->philo_id);
		manager_set_runstate(RUN_STOP, philo->manager);
	}		
}

void	*philo_routine(t_philo *philo)
{
	int		state;

	while (1)
	{
		state = manager_get_runstate(philo->manager);
		if ((philo->philo_id % 2 && state == RUN_ODD) || state == RUN_ALL)
		{
			dine(philo);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
