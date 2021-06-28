/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:19:00 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 17:50:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_atoi(t_tests *tester)
{
	long long	result;
	int			error;

	result = ft_atoi("42", &error);
	ft_assert_cmp(result, 42, "ft_atoi: should return good number", tester);
	ft_assert_cmp(error, 0, "ft_atoi: should not detect error", tester);
	result = ft_atoi("42abc", &error);
	ft_assert_cmp(result, 42, "ft_atoi: should return good number", tester);
	result = ft_atoi("42abc", NULL);
	ft_assert_cmp(result, 42, "ft_atoi: should return good number", tester);
	ft_assert_cmp(error, 1, "ft_atoi: should detect error", tester);
	result = ft_atoi("10000000000000", NULL);
	ft_assert_cmp(error, 1, "ft_atoi: > INT_MAX should be error", tester);
	result = ft_atoi("-10000000000000", NULL);
	ft_assert_cmp(error, 1, "ft_atoi: > INT_MIN should be error", tester);
}
