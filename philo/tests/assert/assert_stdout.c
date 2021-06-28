/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:30:20 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 12:57:25 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"
#include <stdlib.h>

t_stdtest	init_test_stdout(int out_fd)
{
	t_stdtest	stdtest;

	stdtest.read_fd = redirect_out(&stdtest.backup_fd, out_fd);
	stdtest.out_fd = out_fd;
	return (stdtest);
}

void	ft_assert_stdout(t_stdtest stdtest, char *exp, char *behavior, t_tests *tests)
{
	char	*result;
	
	result = redirect_str(stdtest.backup_fd, stdtest.out_fd, stdtest.read_fd);
	if (!result)
		return ;
	ft_assert_strcmp(result, exp, behavior, tests);
	free(result);
}
