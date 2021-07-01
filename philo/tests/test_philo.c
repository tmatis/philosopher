/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:42:04 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/01 11:46:55 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_philo_is_dead(t_tests *tester)
{
	t_philo		philo;
	t_manager	manager;
	t_config	config;
	
	manager.start_time = get_actual_time() - 40;
	philo.last_meal = 0;
	config.time_to_die = 100;
	manager.config = config;
	philo.manager = &manager;
	ft_assert_cmp(philo_is_dead(&philo), 0, "philo_is_dead: not dead", tester);
	manager.start_time = get_actual_time() - 101;
	philo.last_meal = 0;
	config.time_to_die = 100;
	manager.config = config;
	philo.manager = &manager;
	ft_assert_cmp(philo_is_dead(&philo), 1, "philo_is_dead: not dead", tester);
}

void	test_is_counter_reached(t_tests *tester)
{
	t_timems start;

	start = get_actual_time();
	ft_assert_cmp(is_counter_reached(200, start), 0, "is_counter_reached: not reached", tester);
	ft_assert_cmp(is_counter_reached(200, start - 300), 1, "is_counter_reached: reached", tester);
}
