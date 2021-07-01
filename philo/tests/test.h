/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:22:30 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/01 11:46:06 by tmatis           ###   ########.fr       */
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
void	test_ft_atoi(t_tests *tester);
void	test_parse_args(t_tests *tester);
void	test_setup_manager(t_tests *tester);
void	test_philo_is_dead(t_tests *tester);
void	test_is_counter_reached(t_tests *tester);

#endif
