/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:36:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/01 16:33:25 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	lock_fork_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_mutex);
	if (philo->manager->config.philo_count > 1)
	{
		if (philo->philo_id == philo->manager->config.philo_count)
			pthread_mutex_lock(&philo->manager->philo_array[0].fork_mutex);
		else
			pthread_mutex_lock(
				&philo->manager->philo_array[philo->philo_id].fork_mutex);
	}		
}

static void	unlock_fork_mutex(t_philo *philo)
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

int	get_fork(t_philo *philo, int **fork_left, int **fork_right)
{
	if (philo->manager->config.philo_count > 1)
	{
		if (philo->philo_id == philo->manager->config.philo_count)
			*fork_right = &philo->manager->philo_array[0].fork;
		else
			*fork_right
				= &philo->manager->philo_array[philo->philo_id].fork;
	}
	else
		return (1);
	*fork_left = &philo->fork;
	return (0);
}

int	take_forks(t_philo *philo)
{
	int		*fork_left;
	int		*fork_right;
	int		return_value;

	lock_fork_mutex(philo);
	if (get_fork(philo, &fork_left, &fork_right))
		return_value = 1;
	else if (*fork_left == FORK_AVAILABLE && *fork_right == FORK_AVAILABLE)
	{
		*fork_left = FORK_TAKEN;
		printf("%lli %i has taken a fork\n",
			get_relative_time(philo->manager->start_time), philo->philo_id);
		*fork_right = FORK_TAKEN;
		printf("%lli %i has taken a fork\n",
			get_relative_time(philo->manager->start_time), philo->philo_id);
		return_value = 0;
	}	
	else
		return_value = 1;
	unlock_fork_mutex(philo);
	return (return_value);
}

void	drop_forks(t_philo *philo)
{
	int		*fork_left;
	int		*fork_right;

	lock_fork_mutex(philo);
	if (!get_fork(philo, &fork_left, &fork_right))
	{
		*fork_left = FORK_AVAILABLE;
		*fork_right = FORK_AVAILABLE;
	}
	unlock_fork_mutex(philo);
}
