/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:43:34 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/17 21:30:05 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strtoken_w_o_delim(char *str, int delim)
{
	size_t	i;
	char	*token;

	i = 0;
	while (str[i] && str[i] != delim)
		++i;
	token = ft_strndup(str, i);
	if (!token)
		return (NULL);
	return (token);
}

static int	ft_cpy(char **dest_line, char **temp)
{
	//char	*free_er;
	size_t	remaininglen;

	if (!strchr(*temp, '\n'))
	{
		*dest_line = ft_strdup(*temp);
		// *dest_line = ft_strjoin(*dest_line, free_er);
		//free(*temp);
		//free(free_er);
		//temp = NULL;
		return(0); // finished file
	}
	*dest_line = ft_strtoken_w_o_delim(*temp, '\n');
	//if (!*dest_line)
	//	return (-1); //malloc error
	remaininglen = ft_strlen(strchr(*temp, '\n'));
	ft_memmove(*temp, (strchr(*temp, '\n') + 1), remaininglen);
	return (1); // file not finished
}

int	get_next_line(const int fd, char **line)
{
	ssize_t		r_value;
	static char	*temp = "";
	char		buf[BUFF_SIZE + 1];
	char		*free_er;

	r_value = BUFF_SIZE;
	ft_memset(buf, 0, (BUFF_SIZE + 1));
	while (r_value != -1)
	{
		if (strchr(temp, '\n') || r_value < BUFF_SIZE)
		{
			return(ft_cpy(line, &temp)); //"copy finished"
		}
		while (!strchr(buf, '\n') && r_value == BUFF_SIZE)
		{
			free_er = temp;
			r_value = read(fd, &buf, BUFF_SIZE);
			buf[r_value] = '\0';
			temp = ft_strjoin (temp, buf);
			//free(free_er);
			//if (temp == NULL)
				//return (-1); //"Malloc error"
			
		}
	}
	return (-1);			 //"read error"
}