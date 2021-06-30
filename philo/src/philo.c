/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:23:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/30 11:39:41 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->manager->run_simulation_mutex);
		if ((philo->philo_id % 2 && philo->manager->run_simulation == RUN_ODD)
			|| philo->manager->run_simulation == RUN_ALL)
		{
			pthread_mutex_unlock(&philo->manager->run_simulation_mutex);
			printf("i'm running and my philo id is %i\n", philo->philo_id);
			while (1)
			{
				pthread_mutex_lock(&philo->manager->run_simulation_mutex);
				if (philo->manager->run_simulation == RUN_STOP)
				{
					pthread_mutex_unlock(&philo->manager->run_simulation_mutex);
					printf("philo: %i is stopping \n", philo->philo_id);
					return (NULL);
				}
				pthread_mutex_unlock(&philo->manager->run_simulation_mutex);
				usleep(100);
			}
		}
		else
			pthread_mutex_unlock(&philo->manager->run_simulation_mutex);
		usleep(100);
	}
	return (NULL);
}
