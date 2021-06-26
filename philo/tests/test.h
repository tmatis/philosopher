/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:22:30 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/25 14:15:38 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H

# include "../src/philo.h"
# include "assert/assert.h"

void	test_get_actual_time(t_tests *tester);
void	test_get_relative_time(t_tests *tester);
int		is_in_range(int n, int ref, int range);
void	test_ft_usleep(t_tests *tester);

#endif
