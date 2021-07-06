/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:31:34 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/06 19:51:59 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/wait.h>
#include <signal.h>

t_philo	init_philo(t_config config, int n_philo)
{
	t_philo	philo;

	philo.config = config;
	philo.philo_id = n_philo + 1;
	philo.action = ACTION_EATING;
	philo.last_meal = 0;
	philo.meal_counter = 0;
	return (philo);
}

void	kill_allprocess(pid_t *pid, int philo_count)
{
	int		i;

	i = 0;
	while (i < philo_count)
		kill(pid[i++], SIGKILL);
}

void	end_process(t_config config, pid_t *pid, int i)
{
	sem_post(config.sem_run_even);
	ft_usleep(2);
	sem_post(config.sem_run_odd);
	waitpid(-1, NULL, 0);
	kill_allprocess(pid, i--);
	free(pid);
	while (i--)
		waitpid(-1, NULL, 0);
}

void	manage_process(t_config config)
{
	int		i;
	pid_t	*pid;

	pid = malloc(config.philo_count * sizeof(pid_t));
	if (!pid)
		return ;
	i = 0;
	config.start_time = get_actual_time();
	while (i < config.philo_count)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			puterror("philo", "manage_process", "fork error");
			break ;
		}
		if (pid[i] == 0)
		{
			philo_routine(init_philo(config, i));
			free(pid);
		}
		i++;
	}
	end_process(config, pid, i);
}

int	main(int argc, char *argv[])
{
	t_config	config;

	if (parse_args(argc - 1, argv + 1, &config) < 0)
		return (1);
	unlink_sems();
	open_sems(&config);
	manage_process(config);
	close_sems(config);
}
