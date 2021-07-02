/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:43:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/02 11:37:44 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define RUN_WAIT 0
# define RUN_ODD 1
# define RUN_ALL 2
# define RUN_STOP 3

# define ACTION_EATING 0
# define ACTION_SLEEPING 1
# define ACTION_THINKING 2

# ifndef PERF_DELAY
#  define PERF_DELAY 300
# endif

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

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

typedef struct s_manager
{
	t_config		config;
	t_timems		start_time;
	struct s_philo	*philo_array;
	pthread_t		*philo_threads;
	int				run_simulation;
	pthread_mutex_t	run_simulation_mutex;

}	t_manager;

typedef struct s_philo
{
	t_config		config;
	int				philo_id;
	int				meal_counter;
	t_timems		last_meal;
	pthread_mutex_t	fork_mutex;
	int				is_dead;
	int				action;
	t_manager		*manager;
}	t_philo;

void		puterror(char *name, char *location, char *error);
void		ft_usleep(t_timems ms);
t_timems	get_relative_time(t_timems start_time);
t_timems	get_actual_time(void);
int			ft_atoi(const char *str, int *error_nullable);
int			parse_args(int argc, char **argv, t_config *config);
int			manager_setup(t_manager *manager);
void		manager_destroy(t_manager manager);
void		*philo_routine(t_philo *philo);
void		manager_set_runstate(int run_state, t_manager *manager);
int			manager_get_runstate(t_manager *manager);
int			philo_is_dead(t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
int			is_counter_reached(t_timems target, t_timems relative_start);
void		manager_wait_threads(t_manager manager);
int			stop_condition(t_philo *philo);
void		action_eat(t_philo *philo);
void		action_sleep(t_philo *philo);
void		action_think(t_philo *philo);

#endif
