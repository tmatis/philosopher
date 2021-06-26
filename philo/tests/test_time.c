/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:25:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/26 14:44:13 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <sys/time.h>
#include <unistd.h>

void	test_get_actual_time(t_tests *tester)
{
	ft_assert(get_actual_time() != 0, "get_actual_time: not 0", tester);
	ft_assert(get_actual_time() > 0, "get_actual_time: > 0", tester);
}

void	test_get_relative_time(t_tests *tester)
{
	t_timems	start_time;

	start_time = get_actual_time();
	ft_assert(0 >= get_relative_time(start_time),
		"get_relative_time: is almost 0", tester);
	usleep(10000);
	ft_assert(10 <= get_relative_time(start_time),
		"get_relative_time: after usleep ", tester);
}

void	test_ft_usleep(t_tests *tester)
{
	t_timems	start_time;
	t_timems	relative_time;
	t_timems	sleep_time;

	sleep_time = 1;
	while (sleep_time <= 1000)
	{
		start_time = get_actual_time();
		ft_usleep(sleep_time);
		relative_time = get_relative_time(start_time);
		ft_assert(is_in_range(relative_time, sleep_time, 3),
			"ft_usleep: hard test", tester);
		sleep_time *= 2;
	}
	start_time = get_actual_time();
}
