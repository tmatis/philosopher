/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:42:16 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 17:52:21 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str, int *error_nullable)
{
	int					sign;
	long long unsigned	n;
	long long			result;

	sign = 1;
	n = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
		n = n * 10 + ((*str++) - 48);
	if (error_nullable && *str)
		*error_nullable = 1;
	else if (error_nullable)
		*error_nullable = 0;
	result = n * sign;
	if (error_nullable && (result > INT_MAX || result < INT_MIN))
		*error_nullable = 1;
	return (result);
}
