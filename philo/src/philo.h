/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:43:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 18:23:25 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <sys/time.h>

/*
** time in ms;
*/
typedef long long	t_timems;

/*
** philo_config
*/
typedef struct s_config
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	meal_count;
}	t_config;

void		puterror(char *name, char *location, char *error);
void		ft_usleep(t_timems ms);
t_timems	get_relative_time(t_timems start_time);
t_timems	get_actual_time(void);
long long	ft_atoi(const char *str, int *error_nullable);
int			parse_args(int argc, char **argv, t_config *config);

#endif
