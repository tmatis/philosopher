/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 11:37:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/04 18:37:48 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_forks(t_philo *philo)
{
	sem_wait(philo->config.sem_fork);
	if (stop_condition(*philo))
	{
		sem_post(philo->config.sem_fork);
		return (1);
	}
	write_status("taken a fork", *philo);
	if (philo->config.philo_count == 1)
	{
		while (!stop_condition(*philo))
			usleep(PERF_DELAY);
	}
	else
		sem_wait(philo->config.sem_fork);
	if (stop_condition(*philo))
	{
		sem_post(philo->config.sem_fork);
		return (1);
	}
	write_status("taken a fork", *philo);
	return (0);
}

void	action_eat(t_philo *philo)
{
	t_timems	start;

	if (take_forks(philo))
		return ;
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
