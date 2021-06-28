/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:58:55 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/27 17:06:53 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	(void) config;
	(void)argv;
	return (0);
}
