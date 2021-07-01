/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:14:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/01 12:52:29 by tmatis           ###   ########.fr       */
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
	manager_set_runstate(RUN_ODD, &manager);
	usleep(300);
	manager_set_runstate(RUN_ALL, &manager);
	pause();
	manager_destroy(manager);
}
