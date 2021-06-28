/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:58:55 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 18:10:23 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static int	return_error(void)
{
	puterror("philo", "parse_args", "all args should be a integer");
	return (-1);
}

static int	set_config(int *val, char *n_str)
{
	int	error;

	*val = ft_atoi(n_str, &error);
	if (error)
		return (-1);
	return (0);
}

/*
**	parse args return -1 if error
*/
int	parse_args(int argc, char **argv, t_config *config)
{

	if (argc < 4 || argc > 5)
	{
		puterror("philo", "parse_args", "args count error");
		return (-1);
	}
	if (set_config(&config->philo_count, argv[0]))
		return (return_error());
	if (set_config(&config->time_to_die, argv[1]))
		return (return_error());
	if (set_config(&config->time_to_eat, argv[2]))
		return (return_error());
	if (set_config(&config->time_to_sleep, argv[3]))
		return (return_error());
	if (argc == 5 && set_config(&config->meal_count, argv[4]))
		return (return_error());
	if (argc == 4)
		config->meal_count = -1;
	return (0);
}
