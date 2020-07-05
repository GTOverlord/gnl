/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 07:36:43 by hsillem        #+#    #+#                */
/*   Updated: 2020/01/29 19:38:50 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_read(int fd, char *dst, int len);
int		ft_strnlen(char *str, int len, int nwln);
char	*ft_strjoin(char *s1, char *s2, int len);
int		ft_strchr(void *str, char chr, int i);
int		ft_get_next_line(int fd, char **line, char *buf, int *i);
int		get_next_line(int fd, char **line);

#endif
