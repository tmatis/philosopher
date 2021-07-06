/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:31:44 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/06 20:45:34 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_is_dead(t_philo philo)
{
	return (get_relative_time(philo.config.start_time) - philo.last_meal
		>= philo.config.time_to_die);
}

int	stop_condition(t_philo philo)
{
	return (philo_is_dead(philo)
		|| (philo.config.meal_count != -1
			&& philo.meal_counter >= philo.config.meal_count));
}

void	dine(t_philo philo)
{
	while (!stop_condition(philo))
	{
		if (philo.action == ACTION_EATING)
			action_eat(&philo);
		else if (philo.action == ACTION_SLEEPING)
			action_sleep(&philo);
		else if (philo.action == ACTION_THINKING)
			action_think(&philo);
	}
	if (philo_is_dead(philo))
		write_status("died", philo);
	close_sems(philo.config);
}

void	philo_routine(t_philo philo)
{
	if (!(philo.philo_id % 2))
	{
		sem_wait(philo.config.sem_run_even);
		sem_post(philo.config.sem_run_even);
	}
	else
	{
		sem_wait(philo.config.sem_run_odd);
		sem_post(philo.config.sem_run_odd);
	}
	dine(philo);
}
