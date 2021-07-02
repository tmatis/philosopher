/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:14:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/02 17:28:58 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_manager	manager;

	if (parse_args(argc - 1, argv + 1, &config) < 0)
		return (1);
	manager.config = config;
	if (manager_setup(&manager) < 0)
		return (2);
	manager.start_time = get_actual_time();
	manager_set_runstate(RUN_EVEN, &manager);
	ft_usleep(2);
	manager_set_runstate(RUN_ALL, &manager);
	manager_wait_threads(manager);
	manager_destroy(manager);
}
