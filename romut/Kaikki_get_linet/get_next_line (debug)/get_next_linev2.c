/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:12:02 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/14 20:24:36 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strtoken(char *str, int delim)
{
	size_t	i;
	char	*token;

	i = 0;
	while (str[i] && str[i] != delim)
		++i;
	token = ft_strndup(str, i);
	return (token);
}
static int	ft_cpbuffsize(const int fd, char **temp)
{
	int		bytesread;
	char	buf[BUFF_SIZE];
	char	*newbytes;

	bytesread = read(fd, buf, BUFF_SIZE);
	*newbytes = (char *)malloc(sizeof(char) * bytesread);
	 = ft_strncpy(newbytes, &buf);
	if (*temp == null)
		temp = (char *))ft_memalloc(1);
	ft_strjoin(temp, buf);




	/*while (!ft_strchr(temp, '\n') || readsize <= 0)
	{
		bytesread = read(fd, buf, BUFF_SIZE);
		ft_strjoin(temp, buf);
	}
*/
}

int	get_next_line(const int fd, char **line)
{
	char		*free_er;
	static char	*temp;
	int			readsize;
	
	readsize = ft_cpbuffsize(fd, &temp);
	
	if (ft_strchr(temp, '\n') || readsize <= 0)
	{
		free_er = temp;
		*line = ft_strtoken(temp, '\n');
		temp = (ft_strdup(strchr(temp, '\n') + 1));
		ft_strdel(&free_er);
		return (1);
	}
	return (0);
}
