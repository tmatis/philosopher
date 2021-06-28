/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:36:41 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/28 12:22:13 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
** redirect fd to a tube return a fd to read from that tube
*/
int	redirect_out(int *backup, int out_fd)
{
	int	tube[2];

	if (pipe(tube) < 0)
		printf("pipe error\n");
	*backup = dup(out_fd);
	if (backup < 0)
		exit(1);
	dup2(tube[1], out_fd);
	close(tube[1]);
	return (tube[0]);
}

static char	*stradd(char *s1, char *s2)
{
	char	*dest;
	int		len;

	len = strlen(s2) + 1;
	if (s1)
		len += strlen(s1);
	dest = calloc(len, sizeof(char));
	if (!dest)
		return (NULL);
	if (s1)
	{
		strcpy(dest, s1);
		free(s1);
	}
	strcpy(dest, s2);
	return (dest);
}

static void	restore_fd(int backup_fd, int out_fd, int read_fd)
{
	close(read_fd);
	close(out_fd);
	dup2(backup_fd, out_fd);
	close(backup_fd);
}

/*
** return a string from fd.
*/
char	*redirect_str(int backup_fd, int out_fd, int read_fd)
{
	char	buff[BUFSIZ];
	int		read_size;
	char	*dest;

	close(out_fd);
	dest = NULL;
	read_size = read(read_fd, buff, sizeof(buff) - 1);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		dest = stradd(dest, buff);
		read_size = read(read_fd, buff, sizeof(buff) - 1);
	}
	if (!dest)
		dest = strdup("");
	restore_fd(backup_fd, out_fd, read_fd);
	if (read_size < 0)
	{
		if (dest)
			free(dest);
		return (NULL);
	}
	return (dest);
}
