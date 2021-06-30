/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:14:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/30 11:41:32 by tmatis           ###   ########.fr       */
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
	manager_set_run(RUN_ODD, &manager);
	ft_usleep(1000);
	manager_set_run(RUN_ALL, &manager);
	ft_usleep(1000);
	manager_set_run(RUN_STOP, &manager);
	ft_usleep(1000);
	manager_destroy(manager);
	
}
