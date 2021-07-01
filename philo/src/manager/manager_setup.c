/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:02:54 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/01 16:37:09 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>
#include <stdlib.h>

static int	init_philo(t_manager *manager)
{
	int		i;

	i = 0;
	while (i < manager->config.philo_count)
	{
		if (pthread_mutex_init(&manager->run_simulation_mutex, NULL) < 0)
		{
			while (i--)
				pthread_mutex_destroy(&manager->philo_array[i].fork_mutex);
			return (-1);
		}
		manager->philo_array[i].manager = manager;
		manager->philo_array[i].philo_id = i + 1;
		manager->philo_array[i].last_meal = 0;
		manager->philo_array[i].meal_counter = 0;
		manager->philo_array[i].fork = FORK_AVAILABLE;
		manager->philo_array[i].action = ACTION_EATING;
		if (pthread_create(&manager->philo_threads[i], NULL,
				(void *)(void *)philo_routine, &manager->philo_array[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	manager_setup(t_manager *manager)
{
	manager->philo_array
		= malloc((manager->config.philo_count) * sizeof(t_philo));
	if (!manager->philo_array)
	{
		puterror("philo", "setup_manager", "philosopher allocation fail");
		return (-1);
	}
	manager->philo_threads
		= malloc(manager->config.philo_count * sizeof(pthread_t));
	if (!manager->philo_threads)
	{
		puterror("philo", "setup_manager", "threads allocation fail");
		free(manager->philo_array);
		return (-1);
	}
	manager->run_simulation = RUN_WAIT;
	if (pthread_mutex_init(&manager->run_simulation_mutex, NULL) < 0
		|| init_philo(manager) < 0)
	{
		puterror("philo", "setup_manager", "philosopher mutex fail");
		return (-1);
	}
	return (0);
}

void	manager_destroy(t_manager manager)
{
	int	i;

	free(manager.philo_array);
	free(manager.philo_threads);
	pthread_mutex_destroy(&manager.run_simulation_mutex);
	i = 0;
	while (i < manager.config.philo_count)
	{
		pthread_mutex_destroy(&manager.philo_array[i].fork_mutex);
		i++;
	}
}

void	manager_wait_threads(t_manager manager)
{
	int	i;

	i = 0;
	while (i < manager.config.philo_count)
		pthread_join(manager.philo_threads[i++], NULL);
}
