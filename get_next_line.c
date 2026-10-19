/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 09:33:53 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/14 15:26:16 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ch_buf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	return (i);
}

static char	*ft_read_line(int fd, char *curline)
{
	int		flag;
	char	*buf;
	char	*jj;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (free(curline), NULL);
	flag = read(fd, buf, BUFFER_SIZE);
	while (flag > 0)
	{
		buf[flag] = '\0';
		jj = ft_strjoin(curline, buf);
		if (!jj)
			return (free(buf), free(curline), NULL);
		curline = jj;
		if (ch_buf(buf) != flag)
			break ;
		flag = read(fd, buf, BUFFER_SIZE);
	}
	if (flag < 0)
		return (free(curline), free(buf), NULL);
	free(buf);
	return (curline);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*split_lin;
	char		*cop;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, line);
	if (!line || line[0] == '\0')
		return (free(line), line = NULL, NULL);
	i = ch_buf(line);
	if (line[i] == '\n')
		i++;
	split_lin = ft_substr(line, 0, i);
	cop = ft_substr(line, i, ft_strlen(line) - i);
	free(line);
	line = cop;
	return (split_lin);
}
