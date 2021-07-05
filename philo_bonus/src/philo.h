/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:43:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/05 11:52:38 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define ACTION_EATING 0
# define ACTION_SLEEPING 1
# define ACTION_THINKING 2

# ifndef PERF_DELAY
#  define PERF_DELAY 300
# endif

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
/*
** time in ms;
*/
typedef long long	t_timems;

/*
** philo_config
*/
typedef struct s_config
{
	t_timems	start_time;
	int			philo_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meal_count;
	sem_t		*sem_fork;
	sem_t		*sem_run_even;
	sem_t		*sem_run_odd;
	sem_t		*sem_write;
}	t_config;

typedef struct s_philo
{
	t_config		config;
	int				philo_id;
	int				meal_counter;
	t_timems		last_meal;
	int				action;
}	t_philo;

void		puterror(char *name, char *location, char *error);
void		putstr_fd(char *str, int fd);
void		ft_usleep(t_timems ms);
t_timems	get_relative_time(t_timems start_time);
t_timems	get_actual_time(void);
int			is_counter_reached(t_timems target, t_timems relative_start);
int			ft_atoi(const char *str, int *error_nullable);
int			parse_args(int argc, char **argv, t_config *config);
char		*ft_itoa(t_timems n, char *dest);
void		unlink_sems(void);
int			open_sems(t_config *config);
void		close_sems(t_config config);
void		philo_routine(t_philo config);
void		write_status(char *str, t_philo philo);
int			stop_condition(t_philo philo);
void		action_eat(t_philo *philo);
void		action_sleep(t_philo *philo);
void		action_think(t_philo *philo);

#endif
