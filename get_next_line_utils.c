/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:43:51 by hsillem       #+#    #+#                 */
/*   Updated: 2020/06/24 19:57:28 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_read(int fd, char *dst, int len)
{
	int	result;

	result = read(fd, dst, len);
	if (result == -1)
		return (-1);
	dst[result] = 0;
	return (result);
}

int		ft_strnlen(char *str, int len, int nwln)
{
	int		i;

	i = 0;
	while (i != len && str[i] && str[i] != '\n')
		i++;
	if (i != len && nwln && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*concat;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strnlen(s1, -1, 0);
	len2 = ft_strnlen(s2, 32 - len, 0);
	concat = malloc(len1 + len2 + 1);
	if (!concat)
		free(s1);
	if (!concat)
		return (0);
	i = 0;
	while (i < len1)
	{
		concat[i] = s1[i];
		i++;
	}
	free(s1);
	while (i < len1 + len2 + 1)
	{
		concat[i] = s2[i - len1] * (i != len1 + len2);
		i++;
	}
	return (concat);
}

int		ft_strchr(char *str, char chr, int i)
{
	while (i < 32 && str[i])
	{
		if (str[i] == chr)
			return (i + 1);
		i++;
	}
	return (0);
}

int		ft_get_next_line(int fd, char **line, char *buf, int *i)
{
	int	buflen;

	if (!**line)
		*line = ft_strjoin(*line, buf + *i, *i);
	if (!ft_strchr(buf, '\n', *i))
	{
		*i = 0;
		buflen = ft_read(fd, buf, 32);
		if (buflen == -1)
		{
			free(*line);
			return (-1);
		}
		*line = ft_strjoin(*line, buf + *i, *i);
	}
	if (!*line)
		return (-1);
	if (buflen != 32)
		buflen = ft_strchr(buf, '\n', *i);
	return (buflen);
}
