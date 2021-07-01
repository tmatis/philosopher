/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:45:36 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/30 13:30:09 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	manager_set_runstate(int run_state, t_manager *manager)
{
	pthread_mutex_lock(&manager->run_simulation_mutex);
	manager->run_simulation = run_state;
	pthread_mutex_unlock(&manager->run_simulation_mutex);
}

int	manager_get_runstate(t_manager *manager)
{
	int	state;

	pthread_mutex_lock(&manager->run_simulation_mutex);
	state = manager->run_simulation;
	pthread_mutex_unlock(&manager->run_simulation_mutex);
	return (state);
}
