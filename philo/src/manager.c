/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:02:54 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/29 18:20:27 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static int	init_philo(t_manager *manager)
{
	int		i;

	i = 0;
	while (i < manager->config.philo_count)
	{
		if (pthread_mutex_init(&manager->stop_simulation_mutex, NULL) < 0)
		{
			while (i--)
				pthread_mutex_destroy(&manager->philo_array[i].fork_mutex);
			return (-1);
		}
		manager->philo_array[i].manager = manager;
		manager->philo_array[i].philo_id =  i + 1;
		manager->philo_array[i].last_meal = 0;
		manager->philo_array[i].meal_counter = 0;
		manager->philo_array[i].fork = FORK_AVAILABLE;
		i++;
	}
	return (0);
}

int	setup_manager(t_manager *manager)
{
	manager->philo_array
		= malloc((manager->config.philo_count) * sizeof(t_philo));
	if (!manager->philo_array)
	{
		puterror("philo", "setup_manager", "philosopher allocation fail");
		return (-1);
	}
	manager->stop_simulation = 0;
	if (pthread_mutex_init(&manager->stop_simulation_mutex, NULL) < 0
			|| init_philo(manager) < 0)
		return (-1);
	return (0);
}

void	destroy_manager(t_manager manager)
{
	int	i;

	i = 0;
	while (i < manager.config.philo_count)
	{
		pthread_mutex_destroy(&manager.philo_array[i].fork_mutex);
		i++;
	}
}
