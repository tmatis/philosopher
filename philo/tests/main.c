/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:48:57 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/29 18:33:26 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

static void	testing(t_tests *tester)
{
	test_get_actual_time(tester);
	test_get_relative_time(tester);
	test_ft_usleep(tester);
	test_ft_atoi(tester);
	test_parse_args(tester);
	test_setup_manager(tester);
}

int	main(int argc, char **argv)
{
	int		log_level;
	t_tests	tests;

	log_level = 2;
	if (argc > 1)
		log_level = atoi(argv[1]);
	else
		printf("No log level specified, set to 2\n");
	tests = init_tester("Philosoper", log_level);
	tests_header(tests);
	testing(&tests);
	tests_result(&tests);
	if (tests.tests_failed)
		return (1);
	return (0);
}
