/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:31:57 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/06 19:43:48 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <fcntl.h>

void	unlink_sems(void)
{
	sem_unlink("fork");
	sem_unlink("run_even");
	sem_unlink("run_odd");
	sem_unlink("write");
}

static int	open_sems_2(t_config *config)
{
	config->sem_run_odd = sem_open("run_odd", O_RDWR | O_CREAT, 0664, 0);
	if (config->sem_run_even == SEM_FAILED)
	{
		sem_close(config->sem_run_even);
		sem_close(config->sem_fork);
		return (-1);
	}
	config->sem_write = sem_open("write", O_RDWR | O_CREAT, 0664, 1);
	if (config->sem_write == SEM_FAILED)
	{
		sem_close(config->sem_fork);
		sem_close(config->sem_run_even);
		sem_close(config->sem_run_odd);
		return (-1);
	}
	return (0);
}

int	open_sems(t_config *config)
{
	config->sem_fork = sem_open("fork", O_RDWR | O_CREAT, 0664,
			config->philo_count);
	if (config->sem_fork == SEM_FAILED)
		return (-1);
	config->sem_run_even = sem_open("run_even", O_RDWR | O_CREAT, 0664, 0);
	if (config->sem_run_even == SEM_FAILED)
	{
		sem_close(config->sem_fork);
		return (-1);
	}
	return (open_sems_2(config));
}

void	close_sems(t_config config)
{
	sem_close(config.sem_fork);
	sem_close(config.sem_run_odd);
	sem_close(config.sem_run_even);
	sem_close(config.sem_write);
}
