/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:30:58 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/05 11:54:04 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

static int	streq(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

void	write_status(char *str, t_philo philo)
{
	char		buff[50];
	char		dest[4048];

	ft_itoa(get_relative_time(philo.config.start_time), dest);
	ft_strcat(dest, " ");
	ft_strcat(dest, ft_itoa(philo.philo_id, buff));
	ft_strcat(dest, " ");
	ft_strcat(dest, str);
	ft_strcat(dest, "\n");
	sem_wait(philo.config.sem_write);
	write(STDOUT_FILENO, dest, ft_strlen(dest));
	if (!streq(str, "died"))
		sem_post(philo.config.sem_write);
}
