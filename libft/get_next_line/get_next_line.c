/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:43:36 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/19 14:44:23 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		total_characters;
	char	*str_space;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
		return (gnl_strdup(s1));
	total_characters = gnl_strlen(s1) + gnl_strlen(s2);
	str_space = (char *)malloc((total_characters + 1) * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	while (s1[i])
		str_space[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str_space[i++] = s2[j++];
	str_space[i] = '\0';
	return (str_space);
}

char	*get_da_file(int fd, char *rdin)
{
	int		rd;
	char	rdsponge[BUFFER_SIZE + 1];
	char	*temp;

	if (rdin == NULL)
		rdin = gnl_strdup("");
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, rdsponge, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		if (rd == 0)
			break ;
		rdsponge[rd] = '\0';
		temp = rdin;
		rdin = gnl_strjoin(rdin, rdsponge);
		free(temp);
		if (!rdin)
			return (NULL);
		if (gnl_strchr(rdin, '\n'))
			break ;
	}
	return (rdin);
}

void	*shorty(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (len == 0 || dst == src || (dst == NULL && src == NULL))
		return (dst);
	if (d < s || d >= (s + len))
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = d + len;
		s = s + len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}

static char	*letitgo(char *rdsponge, char **line)
{
	char	*endpoint;
	size_t	l2b_trim;
	ssize_t	cut;

	endpoint = gnl_strchr(rdsponge, '\n');
	if (!endpoint)
		endpoint = gnl_strchr(rdsponge, '\0');
	l2b_trim = endpoint - rdsponge;
	*line = gnl_substr(rdsponge, 0, l2b_trim + (endpoint && *endpoint == '\n'));
	if (!*line)
	{
		free(rdsponge);
		return (NULL);
	}
	cut = gnl_strlen(rdsponge) - l2b_trim;
	if (*(endpoint) == '\0')
	{
		free(rdsponge);
		return (NULL);
	}
	shorty(rdsponge, &rdsponge[l2b_trim + 1], cut);
	return (rdsponge);
}

char	*get_next_line(int fd)
{
	static char	*rdsponge;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (free(rdsponge), rdsponge = NULL, NULL);
	rdsponge = get_da_file(fd, rdsponge);
	if (!rdsponge)
		return (NULL);
	if (*rdsponge == '\0')
		return (free(rdsponge), rdsponge = NULL, NULL);
	if (gnl_strlen(rdsponge) == 1 && *rdsponge == '\n')
	{
		free(rdsponge);
		rdsponge = NULL;
		return (gnl_strdup("\n"));
	}
	rdsponge = letitgo(rdsponge, &line);
	return (line);
}
