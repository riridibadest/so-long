/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:55 by yuerliu           #+#    #+#             */
/*   Updated: 2025/04/13 22:36:26 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	gnl_strlen(char const *str);
size_t	gnl_strlcpy(char *dest, const char *src, size_t size);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*get_da_file(int fd, char *rdin);
char	*gnl_strchr(const char *str, int character);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
void	*shorty(void *dst, const void *src, size_t len);

#endif