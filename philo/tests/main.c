/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:48:57 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/24 14:34:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert/assert.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		log_level;
	t_tests	tests;
	
	log_level = 3;
	if (argc > 1)
		log_level = atoi(argv[1]);
	else
		printf("No log level specified, set to 3\n");
	tests = init_tester("Philosoper", log_level);
	tests_header(tests);
	tests_result(&tests);
	if (tests.tests_failed)
		return (1);
	return (0);
}
