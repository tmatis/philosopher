/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 11:37:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/04 12:16:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	action_eat(t_philo *philo)
{
	t_timems	start;

	philo->last_meal = get_relative_time(philo->config.start_time);
	sem_wait(philo->config.sem_fork);
	write_status("taken a fork", *philo);
	sem_wait(philo->config.sem_fork);
	write_status("taken a fork", *philo);
	philo->last_meal = get_relative_time(philo->config.start_time);
	write_status("is eating", *philo);
	start = get_actual_time();
	while (!stop_condition(*philo)
		&& !is_counter_reached(philo->config.time_to_eat, start))
		usleep(PERF_DELAY);
	philo->meal_counter++;
	sem_post(philo->config.sem_fork);
	sem_post(philo->config.sem_fork);
	philo->action = ACTION_SLEEPING;
}

void	action_sleep(t_philo *philo)
{
	t_timems	start;

	start = get_actual_time();
	write_status("is sleeping", *philo);
	while (!stop_condition(*philo)
		&& !is_counter_reached(philo->config.time_to_sleep, start))
		usleep(PERF_DELAY);
	philo->action = ACTION_THINKING;
}

void	action_think(t_philo *philo)
{
	write_status("is thinking", *philo);
	philo->action = ACTION_EATING;
}
