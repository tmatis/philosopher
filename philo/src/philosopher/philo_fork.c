/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:36:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/04 18:11:40 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_mutex);
	write_status("taken a fork", philo);
	if (philo->manager->config.philo_count > 1)
	{
		if (philo->philo_id == philo->manager->config.philo_count)
		{
			pthread_mutex_lock(&philo->manager->philo_array[0].fork_mutex);
		}
		else
			pthread_mutex_lock(
				&philo->manager->philo_array[philo->philo_id].fork_mutex);
		write_status("taken a fork", philo);
	}
	else
		return (1);
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_mutex);
	if (philo->manager->config.philo_count > 1)
	{
		if (philo->philo_id == philo->manager->config.philo_count)
			pthread_mutex_unlock(&philo->manager->philo_array[0].fork_mutex);
		else
			pthread_mutex_unlock(
				&philo->manager->philo_array[philo->philo_id].fork_mutex);
	}		
}
