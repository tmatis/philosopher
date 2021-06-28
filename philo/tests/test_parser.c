/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:29:41 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 13:50:50 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <unistd.h>
#include <stdlib.h>

const static char *not_good[] = {"1234a", "1234", "1234", "1234"};
const static char *good[] = {"10", "124", "125", "126"};
const static char *meal_count[] = {"10", "124", "125", "126", "127"};

static void	test_argc(t_tests *tester)
{
	t_stdtest	stdtest;

	stdtest = init_test_stdout(STDERR_FILENO);
	ft_assert_cmp(parse_args(3, NULL, NULL),  -1,
		"parse_args: not enought args", tester);
	ft_assert_stdout(stdtest, "philo: parse_args: args count error\n",
			"parse_args: not enought args output", tester);
	stdtest = init_test_stdout(STDERR_FILENO);
	ft_assert_cmp(parse_args(6, NULL, NULL),  -1,
		"parse_args: too many args", tester);
	ft_assert_stdout(stdtest, "philo: parse_args: args count error\n",
			"parse_args: too many args output", tester);
}

static void	test_not_number(t_tests *tester)
{
	t_stdtest	stdtest;

	stdtest = init_test_stdout(STDERR_FILENO);
	ft_assert_cmp(parse_args(4, (char **)not_good, NULL),  -1,
		"parse_args: not a number", tester);
	ft_assert_stdout(stdtest,
			"philo: parse_args: all args should be a number\n",
			"parse_args: not a number output", tester);
}

static void	test_good(t_tests *tester)
{
	t_config	config;

	ft_assert_cmp(parse_args(4, (char **)good, &config), 0,
		"parse_args: good case", tester);
	ft_assert_cmp(config.philo_count, 10, "parse_args: : 10 philo", tester);
	ft_assert_cmp(config.time_to_die, 124, "parse_args: : 124 time_to_die",
		tester);
	ft_assert_cmp(config.time_to_eat, 125, "parse_args: : 124 time_to_die",
		tester);
	ft_assert_cmp(config.time_to_sleep, 126, "parse_args: : 124 time_to_die",
		tester);
	ft_assert_cmp(config.meal_count, -1, "parse_args: : -1 last_meal",
		tester);
	ft_assert_cmp(parse_args(4, (char **)meal_count, &config), 0,
		"parse_args: good case", tester);
	ft_assert_cmp(config.philo_count, 10, "parse_args: : 10 philo", tester);
	ft_assert_cmp(config.time_to_die, 124, "parse_args: : 124 time_to_die",
		tester);
	ft_assert_cmp(config.time_to_eat, 125, "parse_args: : 124 time_to_die",
		tester);
	ft_assert_cmp(config.time_to_sleep, 126, "parse_args: : 124 time_to_die",
		tester);
	ft_assert_cmp(config.meal_count, 127, "parse_args: : 127 last_meal",
		tester);
}


void	test_parse_args(t_tests *tester)
{
	test_argc(tester);
	test_not_number(tester);
	test_good(tester);
}