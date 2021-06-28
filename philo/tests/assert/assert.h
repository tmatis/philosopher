/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:19:08 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 18:22:48 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_H

# define ASSERT_H

# include <stdio.h>
# include <string.h>

typedef struct s_tests
{
	int		tests_success;
	int		tests_failed;
	int		log_level;
	char	name[256];
}				t_tests;

typedef struct s_stdtest
{
	int	out_fd;
	int	backup_fd;
	int	read_fd;
}	t_stdtest;

t_tests			init_tester(char name[256], int log_level);
void			tests_header(t_tests tests);
void			tests_result(t_tests *tests);
void			ft_assert(int actual, char *behavior, t_tests *tests);
void			ft_assert_cmp(int act, int exp, char *behavior, t_tests *tests);
void			ft_assert_strcmp(char *act, char *exp, char *behavior,
					t_tests *tests);
int				redirect_out(int *backup, int out_fd);
char			*redirect_str(int backup_fd, int out_fd, int read_fd);
void			printf_printable(char *src);
t_stdtest		init_test_stdout(int out_fd);
void			ft_assert_stdout(t_stdtest stdtest, char *exp,
					char *behavior, t_tests *tests);

#endif
