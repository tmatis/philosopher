/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:14:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/29 18:36:08 by tmatis           ###   ########.fr       */
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
	if (setup_manager(&manager) < 0)
		return (2);
	destroy_manager(manager);
}
