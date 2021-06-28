/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:34:57 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/27 17:17:32 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../philo.h"
#include <sys/time.h>

/*
** take the delay in ms and sleep for the delay
*/
void	ft_usleep(t_timems ms)
{
	t_timems	time_of_day;

	time_of_day = get_actual_time();
	while (get_relative_time(time_of_day) < ms)
		usleep(100);
}

/*
** return time or -1 if error
*/
t_timems	get_actual_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (-1);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

/*
** return relative time or -1 if error
** start_time: time_of_day when started
*/
t_timems	get_relative_time(t_timems start_time)
{
	t_timems	time_of_day;

	time_of_day = get_actual_time();
	if (time_of_day < 0)
		return (-1);
	return (time_of_day - start_time);
}
