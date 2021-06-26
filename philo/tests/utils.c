/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:32:59 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/25 19:35:58 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
/*
** check if the nunber is arround a range of ref
*/
int		is_in_range(int n, int ref, int range)
{
	return (abs(ref - n) < range);
}
