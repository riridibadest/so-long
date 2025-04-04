/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:16:51 by yuerliu           #+#    #+#             */
/*   Updated: 2024/10/27 19:18:23 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	word_len(char const *s, char c);
static char	*word_allo(char const *s, int len);
//static void	free_split(char **split, int count);

static int	handle_word(char **split, char const *s, char c, int *arc)
{
	int	len;

	len = word_len(s, c);
	split[*arc] = word_allo(s, len);
	if (!split[*arc])
	{
		while (*arc > 0)
			free(split[--(*arc)]);
		free(split);
		return (0);
	}
	*arc += 1;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		arc;
	int		len;

	arc = 0;
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = handle_word(split, s, c, &arc);
			if (!len)
				return (NULL);
			s += len;
		}
		else
			s++;
	}
	split[arc] = NULL;
	return (split);
}

static int	count_words(char const *s, char c)
{
	int	wordnb;
	int	wordin;

	wordnb = 0;
	wordin = 0;
	while (*s)
	{
		if (*s != c && wordin == 0)
		{
			wordnb++;
			wordin = 1;
		}
		else if (*s == c)
		{
			wordin = 0;
		}
		s++;
	}
	return (wordnb);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*word_allo(char const *s, int len)
{
	char	*words;

	words = (char *)malloc((len + 1) * sizeof(char));
	if (!words)
		return (NULL);
	ft_strlcpy(words, s, len + 1);
	words[len] = '\0';
	return (words);
}

/*
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		arc;
	int		len;
	int		count;

	count = count_words(s, c);
	if (!s || !(split = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	arc = 0;
	while (*s)
	{
		if (*s != c)
		{
			copy_paste(split, s, arc, c);
			s = s + len;
			arc++;
		}
		s++;
	}
	split[arc] = NULL;
	return (split);
}

int	copy_paste(char **split, char *s, int arc, char c)
{
	int	len;

	len = word_len(s, c);
	if (!(split[arc] = word_allo(s, len)))
	{
		while (arc > 0)
			free(split[--arc]);
		free(split);
		return (NULL);
	}
}
*/
/*
static void	free_split(char **split, int count)
{
	while (count > 0)
		free(split[--count]);
	free(split);
}
*/
/*
char	next_word(const char **s, char c)
{
	if (*s == c){
		s++;
		*s = (char *)malloc((word_len(s, c) + 1) * (sizeof(char)));
		if (!s)
		{
			free(s);
			return (NULL);
		}
		(*s += (word_len(s, c)));
	}
}
*/
/*
static int	count_words(char const *s, char c)
{
	int	wordnb;
	int	wordin;

	wordnb = 0;
	wordin = 0;
	while (*s)
	{
		if (*s != c && wordin == '0')
		{
			wordnb++;
			wordin = 1;
		}
		else if (*s == c)
			wordin = 0;
		s++;
	}
	return (wordnb);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*word_allo(char const *s, int len)
{
	char	*words;

	words = (char *)malloc((len + 1) * (sizeof(char)));
	if (!words)
	{
		return (NULL);
	}
	ft_strlcpy(words, s, len + 1);
	words[len] = '\0';
	return (words);
}
*/
