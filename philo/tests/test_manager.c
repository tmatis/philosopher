/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:23:06 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/30 11:14:35 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

const static char	*g_good[] = {"10", "124", "125", "126"};

void	test_setup_manager(t_tests *tester)
{
	t_manager	manager;
	t_config	config;

	parse_args(4, (char **)g_good, &config);
	//printf("%i\n", config.philo_count);
	manager.config = config;
	manager_setup(&manager);
	ft_assert(manager.philo_array[0].fork == FORK_AVAILABLE,
		"setup_manager: check if manager is ready", tester);
	manager_destroy(manager);
}
