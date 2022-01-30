/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:12:02 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/14 20:24:33 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cpfrombuffertotemp(const int fd, char **temp)
{
	int bytesread;
	char buf[BUFF_SIZE];

	bytesread = 1;
	while (!ft_strchr(temp, '\n') || bytesread > 0)
	{
		bytesread = read(fd, buf, BUFF_SIZE);
		ft_strjoin(&temp, &buf);
	}

}



int	get_next_line(const int fd, char **line)
{
	char		*free_er;
	static char	*temp;
	static int	temp_size;
	int			read_size;

	readsize = ft_cpbuffsize(fd, &temp);
	
	
		if (ft_strchr(temp, '\n') || readsize <= 0)
		{
			free_er = temp;
			*line = ft_strtoken(temp, '\n');
			temp = (ft_strdup(strchr(temp, '\n') + 1));
			ft_strdel(&free_er);
			tempsize = ft_strlen(temp)
			return (1);
		}
	

	return (0);
}
