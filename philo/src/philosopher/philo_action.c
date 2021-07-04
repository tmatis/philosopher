/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:38:50 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/04 18:20:26 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	stop_condition(t_philo *philo)
{
	return (philo_is_dead(philo)
		|| manager_get_runstate(philo->manager) == RUN_STOP
		|| (philo->manager->config.meal_count != -1
			&& philo->meal_counter >= philo->manager->config.meal_count));
}

int	is_counter_reached(t_timems target, t_timems relative_start)
{
	return (get_relative_time(relative_start) >= target);
}

void	action_eat(t_philo *philo)
{
	t_timems	start;

	if (take_forks(philo))
	{
		while (!stop_condition(philo))
			usleep(PERF_DELAY);
	}
	if (stop_condition(philo))
	{
		drop_forks(philo);
		return ;
	}
	philo->last_meal = get_relative_time(philo->manager->start_time);
	write_status("is eating", philo);
	start = get_actual_time();
	while (!stop_condition(philo)
		&& !is_counter_reached(philo->manager->config.time_to_eat, start))
		usleep(PERF_DELAY);
	philo->meal_counter++;
	drop_forks(philo);
	philo->action = ACTION_SLEEPING;
}

void	action_sleep(t_philo *philo)
{
	t_timems	start;

	start = get_actual_time();
	write_status("is sleeping", philo);
	while (!stop_condition(philo)
		&& !is_counter_reached(philo->manager->config.time_to_sleep, start))
		usleep(PERF_DELAY);
	philo->action = ACTION_THINKING;
}

void	action_think(t_philo *philo)
{
	write_status("is thinking", philo);
	philo->action = ACTION_EATING;
}
