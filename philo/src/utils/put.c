/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:40:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/24 14:47:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	write(fd, str, i);
}

void	puterror(char *name, char *location, char *error)
{
	putstr_fd(name, STDERR_FILENO);
	putstr_fd(": ", STDERR_FILENO);
	putstr_fd(location, STDERR_FILENO);
	putstr_fd(": ", STDERR_FILENO);
	putstr_fd(error, STDERR_FILENO);
	putstr_fd("\n", STDERR_FILENO);
}
