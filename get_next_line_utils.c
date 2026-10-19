/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:03:44 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/14 15:26:34 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*c;
	size_t		siz;
	size_t		j;

	if (s == NULL)
		return (NULL);
	siz = ft_strlen(s);
	if (siz <= start)
		len = 0;
	else if (len > siz - start)
		len = siz - start;
	c = malloc(len * sizeof(char) + 1);
	if (!c)
		return (NULL);
	j = 0;
	while (j < len)
	{
		c[j] = s[start + j];
		j++;
	}
	c[j] = '\0';
	return (c);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	p = malloc (i * sizeof(char) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	put(char *s1, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		p[j] = s1[i];
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*p;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	p = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	j = put(s1, p);
	while (s2[i])
	{
		p[j] = s2[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (free(s1), p);
}
