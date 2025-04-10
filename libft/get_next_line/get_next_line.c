/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:18 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/09 21:47:29 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// typedef struct test_struct {
// 	int a;
// 	int b;
// 	int c;
// 	int d;
// 	int e;
// 	int f;
// 	const char *test;
// }	t_test_struct;

// void initialize(t_test_struct a); // (what)
// void initialize(t_test_struct *a) {
// 		a->a;
// 		a->b;
// 	}// (where)

// ->24234234 234234234 234234234 23423423 234234234 5345345 354435345
// 24234234 ->234234234 234234234 23423423 234234234 5345345 354435345

// int	len_line(char *patrick)
// {
// 	int	len;

// 	len = 0;
// 	while (patrick[len] && patrick[len] != '\n')
// 		len++;
// 	return (len);
// }
//only used in shorty so ignore for now

// char	*get_one_line(char *rdsponge)
// {
// 	char	*patrick;
// 	int	oh;

// 	if (!rdsponge)
// 		rdsponge = ft_calloc(1, 1);
// 	oh = (len_line(rdsponge));
// 	patrick = ft_calloc((oh + 2), sizeof(char));
// 	if (patrick == NULL)
// 		return (NULL);
// 	oh = 0;
// 	while (rdsponge[oh] && rdsponge[oh] != '\n')
// 	{
// 		patrick[oh] = rdsponge[oh];
// 		oh++;
// 	}
// 	if (rdsponge[oh] == '\n')
// 		patrick[oh] = '\n';
// 	patrick[oh++] = '\0';
// 	return (patrick);
// 	// printf("Patrick %s\n", patrick);

// }
// char	*shorty(char *rdsponge)
// {
// 	char	*sandy;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = len_line(rdsponge);
// 	sandy = ft_calloc((ft_strlen(rdsponge) - len + 1), sizeof(char));
// 	if (sandy == NULL)
// 		return (free(sandy), NULL);
// 	while (rdsponge[len + i])
// 	{
// 		sandy[i] = rdsponge[len + i];
// 		i++;
// 	}
// 	sandy[i] = '\0';
// 	// printf("sandy %s\n", sandy);
// 	free(rdsponge);
// 	return (sandy);
// }
//shorty handled in the gnl function

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
	char	*new_rdsponge;

	printf("DEBUG: letitgo - rdsponge: %p\n", (void *)rdsponge);
	endpoint = gnl_strchr(rdsponge, '\n');
	if (!endpoint)
		endpoint = gnl_strchr(rdsponge, '\0');
	l2b_trim = endpoint - rdsponge;
	*line = gnl_substr(rdsponge, 0, l2b_trim + (endpoint && *endpoint == '\n'));
	printf("DEBUG: Allocated line at %p\n", (void *)*line);
	if (!*line)
	{
		free(rdsponge);
		return (NULL);
	}
	if (*(endpoint) == '\0')
	{
		free(rdsponge);
		return (NULL);
	}
	new_rdsponge = gnl_strdup(endpoint + 1);
	printf("DEBUG: Allocated new_rdsponge at %p\n", (void *)new_rdsponge);
	free(rdsponge);
	printf("DEBUG: Freed rdsponge at %p\n", (void *)rdsponge);
	return (new_rdsponge);
}

char	*get_next_line(int fd)
{
	static char	*rdsponge;
	char		*line;

	rdsponge = NULL;
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

// char	*get_next_line(int fd)
// {
// 	static char	*rdsponge;
// 	char		*line;
// 	char		*ricky;
// 	size_t		l2b_trim;
// 	ssize_t		cut;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
// 	{
// 		free(rdsponge);
// 		rdsponge = NULL;
// 		return (NULL);
// 	}
// 	rdsponge = get_da_file(fd, rdsponge);
// 	if (!rdsponge)
// 		return (NULL);
// 	if (*rdsponge == '\0')
// 	{
// 		free(rdsponge);
// 		rdsponge = NULL;
// 		return (NULL);
// 	}
// 	if (ft_strlen(rdsponge) == 1 && *rdsponge == '\n')
// 	{
// 		free(rdsponge);
// 		rdsponge = NULL;
// 		return (ft_strdup("\n"));
// 	}
// 	ricky = ft_strchr(rdsponge, '\n');
// 	if (!ricky)
// 		ricky = ft_strchr(rdsponge, '\0');
// 	l2b_trim = ricky - rdsponge;
// 	line = ft_substr(rdsponge, 0, l2b_trim + (ricky && *ricky == '\n'));
// 	if (!line)
// 	{
// 		free(rdsponge);
// 		rdsponge = NULL;
// 		return (NULL);
// 	}
// 	cut = ft_strlen(rdsponge) - l2b_trim;
// 	if (*(ricky) == '\0')
// 	{
// 		free(rdsponge);
// 		rdsponge = NULL;
// 	}
// 	else
// 		shorty(rdsponge, &rdsponge[l2b_trim + 1], cut);
// 	return (line);
// }

//line 175 l2b_trim == ft_strlen(rdsponge) is like this

// int	main2(void)
// {
// 	int		fd;
// 	char	*one;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("OH");
// 		return (1);
// 	}
// 	one = get_next_line(fd);
// 	printf("LETSEE: %s", one);
// 	free(one);

// 	one = get_next_line(fd);
// 	printf("LETSEE: %s", one);
// 	free(one);

// 	one = get_next_line(fd);
// 	printf("LETSEE: %s", one);
// 	free(one);

// 	one = get_next_line(fd);
// 	printf("LETSEE: %s", one);
// 	free(one);

// 	one = get_next_line(fd);
// 	printf("LETSEE: %s", one);
// 	free(one);

// 	close(fd);
// 	return (0);
// }
// int main()
// {
// 	system("leaks a.out");
// }

// int main(void)
// {
// 	static char	*rdsponge;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("OH");
// 		return (1);
// 	}
// 	rdsponge = get_da_file(fd, rdsponge);
// 	printf("spongebob1:%s\n", rdsponge);
// }