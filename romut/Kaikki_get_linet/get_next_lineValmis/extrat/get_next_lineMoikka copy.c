/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineMoikka copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:12:02 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/13 16:09:13 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




int get_next_line(const int fd, char **line)
{
	char	*free-er;
	char	buf[BUFF_SIZE];

	while (read(fd, *buf, [BUFF_SIZE]))
	{
		if (*buf = '\n')
		{
			free-er = NULL;
			return (line has been read (1));
		}
		free-er = &line;
		&line = ft_strjoin(&line, buf);
		if(!*line)
		{
			ft_strdel(*line);
			return (Error: insufficient memory);
		}
		free(free-er);
	}
	free-er = NULL;
	return(endoffile (0));
}