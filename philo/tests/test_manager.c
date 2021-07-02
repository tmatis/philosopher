/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:23:06 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/02 11:39:04 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

const static char	*g_good[] = {"10", "124", "125", "126"};

void	test_setup_manager(t_tests *tester)
{
	t_manager	manager;
	t_config	config;

	parse_args(4, (char **)g_good, &config);
	manager.config = config;
	manager_setup(&manager);
	ft_assert(manager.philo_array[0].action == ACTION_EATING,
		"setup_manager: check if manager is ready", tester);
	manager_destroy(manager);
}
