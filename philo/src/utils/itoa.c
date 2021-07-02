/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:41:20 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/02 17:33:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_len(int n)
{
	int			i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_compute(unsigned int n, char *dest, int len)
{
	while (len >= 0)
	{
		dest[len--] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_itoa(t_timems n, char *dest)
{
	int		len;

	len = ft_len(n);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
	{
		dest[0] = '-';
		ft_compute((unsigned int) -n, dest + 1, len - 2);
	}
	else
		ft_compute((unsigned int)n, dest, len - 1);
	return (dest);
}
