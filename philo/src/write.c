/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:30:58 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/02 18:04:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	write_status(char *str, t_philo *philo)
{
	char		buff[50];
	char		dest[4048];

	if (manager_get_runstate(philo->manager) == RUN_STOP)
		return ;
	ft_itoa(get_relative_time(philo->manager->start_time), dest);
	ft_strcat(dest, " ");
	ft_strcat(dest, ft_itoa(philo->philo_id, buff));
	ft_strcat(dest, " ");
	ft_strcat(dest, str);
	ft_strcat(dest, "\n");
	pthread_mutex_lock(&philo->manager->write_mutex);
	write(STDOUT_FILENO, dest, ft_strlen(dest));
	pthread_mutex_unlock(&philo->manager->write_mutex);
}
