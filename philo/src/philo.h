/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:43:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/26 14:46:28 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <sys/time.h>

/*
** time in ms;
*/
typedef long long	t_timems;

void		puterror(char *name, char *location, char *error);
void		ft_usleep(t_timems ms);
t_timems	get_relative_time(t_timems start_time);
t_timems	get_actual_time(void);

#endif
