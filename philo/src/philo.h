/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:43:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/29 18:15:26 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define FORK_AVAILABLE 0
# define FORK_TAKEN 1;

# include <sys/time.h>
# include <pthread.h>
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

typedef	struct s_manager
{
	t_config		config;
	t_timems		start_time;
	struct s_philo	*philo_array;
	int				stop_simulation;
	pthread_mutex_t	stop_simulation_mutex;

}	t_manager;


typedef struct s_philo
{
	t_config		config;
	int				philo_id;
	int				meal_counter;
	t_timems		last_meal;
	int				fork;
	pthread_mutex_t	fork_mutex;
	int				is_dead;
	t_manager		*manager;
}	t_philo;


void		puterror(char *name, char *location, char *error);
void		ft_usleep(t_timems ms);
t_timems	get_relative_time(t_timems start_time);
t_timems	get_actual_time(void);
int			ft_atoi(const char *str, int *error_nullable);
int			parse_args(int argc, char **argv, t_config *config);
int			setup_manager(t_manager *manager);
void		destroy_manager(t_manager manager);

#endif
