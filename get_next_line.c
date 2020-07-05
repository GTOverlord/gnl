/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:43:49 by hsillem       #+#    #+#                 */
/*   Updated: 2020/06/24 19:57:45 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buf[32];
	static int	i;
	int			buflen;

	if (32 < 0 || !line || read(fd, buf, 0) == -1)
		return (-1);
	*line = malloc(sizeof(char) * 1);
	if (!*line)
		return (-1);
	**line = 0;
	buflen = ft_get_next_line(fd, line, buf, &i);
	if (!**line)
		buflen = ft_get_next_line(fd, line, buf, &i);
	if (!*line)
		return (-1);
	while (!ft_strchr(buf, '\n', i) && buflen == 32)
		buflen = ft_get_next_line(fd, line, buf, &i);
	if (buflen < 1)
		return (buflen);
	i = ft_strchr(buf, '\n', i);
	return (1);
}
