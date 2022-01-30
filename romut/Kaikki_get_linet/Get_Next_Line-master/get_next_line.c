/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:56:19 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/23 00:38:14 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char **first, char **second, int howmany2free)
{
	if (howmany2free == 2)
	{
		free(*first);
		free(*second);
		*first = NULL;
		*second = NULL;
	}
	if (howmany2free == 1)
	{
		free(*first);
		*first = NULL;
	}
	if (howmany2free == 999)
	{
		free(*first);
		*first = NULL;
		return (999);
	}
	return (-1);
}

static int	ft_cpyend(char **line, char **buf, const int fd)
{
	char	*free_er;

	free_er = *line;
	*line = ft_strjoin(*line, buf[fd]);
	if (!*line)
		return (ft_free(&free_er, buf, 2));
	free(free_er);
	free(buf[fd]);
	buf[fd] = NULL;
	return (0);
}

static int	ft_cpy(char **line, char **buf, const int fd, ssize_t r_value)
{
	size_t	len;
	char	*free_er;

	if (!ft_strchr(buf[fd], '\n') && r_value < BUFF_SIZE && \
		BUFF_SIZE < ft_strlen(*line))
		return (ft_cpyend(line, buf, fd));
	if (!ft_strchr(buf[fd], '\n'))
	{
		free_er = *line;
		*line = ft_strjoin(*line, buf[fd]);
		if (!line)
			return (ft_free(&free_er, &buf[fd], 2));
		return (ft_free(&free_er, buf, 999));
	}
	free_er = *line;
	*ft_strchr(buf[fd], '\n') = '\0';
	*line = ft_strjoin(*line, buf[fd]);
	ft_free(&free_er, buf, 999);
	if (!*line)
		return (ft_free(&free_er, &buf[fd], 2));
	len = ft_strlen(ft_strchr(buf[fd], '\0') + 1);
	ft_memmove(buf[fd], (ft_strchr(buf[fd], '\0') + 1), len);
	buf[fd][len] = '\0';
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[10240];
	ssize_t		r_value;

	r_value = BUFF_SIZE;
	*line = ft_strnew(1);
	if (!*line)
		return (-1);
	if (!buf[fd])
		buf[fd] = (char *)ft_memalloc(BUFF_SIZE + 1);
	if (!buf[fd])
		return (ft_free(line, &buf[fd], 1));
	while (r_value != -1)
	{
		if (strchr(buf[fd], '\n') || r_value < BUFF_SIZE)
			return (ft_cpy(line, buf, fd, r_value));
		if (ft_strlen(buf[fd]) > 0)
		{
			if (ft_cpy(line, buf, fd, r_value) == -1)
				return (-1);
			ft_memset(buf[fd], '\0', (BUFF_SIZE + 1));
		}
		r_value = read(fd, buf[fd], BUFF_SIZE);
	}
	return (ft_free(line, &buf[fd], 2));
}
