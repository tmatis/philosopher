/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:25:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/27 17:27:24 by tmatis           ###   ########.fr       */
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
	int			is_ok;

	is_ok = 1;
	sleep_time = 1;
	while (sleep_time <= 2000)
	{
		start_time = get_actual_time();
		ft_usleep(sleep_time);
		relative_time = get_relative_time(start_time);
		if (!is_in_range(relative_time, sleep_time, 3))
			is_ok = 0;
		sleep_time *= 4;
	}
	ft_assert(is_ok, "ft_usleep: delay test", tester);
	start_time = get_actual_time();
}
