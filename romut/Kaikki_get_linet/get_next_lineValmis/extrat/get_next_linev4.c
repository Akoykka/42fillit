/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:58:24 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/14 20:24:32 by akoykka          ###   ########.fr       */
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

static int ft_cpyreadbytes(char **dest, char *src int sizeoftemp)
{
	if (i = 0)
	{
		strdup(&dest, src);
		i = i + strlen(src);

	}
	else
	{
		strjoin(&dest, src);
		i = i + strlen(src);
	}

}

int	get_next_line(const int fd, char **line)
{
	static char *temp;
	static int	i;
	char	buf[BUFF_SIZE + 1];
	char	*free_er;

	while (read(fd, &buf, BUFF_SIZE) == BUFF_SIZE)
	{
		i = ft_cpyreadbytes(&temp, &buf, i);
		if (ft_strchr(temp, '\n'))
		{
			free_er = temp;
			*line = ft_strtoken(temp, '\n');
			temp = (ft_strdup(strchr(temp, '\n') + 1));
			ft_strdel(&free_er);
			return (0);
		}	
	}
	ft_cpyreadbytes(&line, &buf, i);
	return (1);
}