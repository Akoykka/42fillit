/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:43:34 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/17 22:32:34 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_errors(char **temp, int errortype)
{
	if (errortype == -1)
	{	
		if (*temp)
			free (temp);
		ft_putendl_fd("Read error", 2);
	}
	if (errortype == -2)
	{
		ft_putendl_fd("Malloc error", 2);
		free (temp);
	}
	return (-1);
}

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
	size_t	len;

	if (!strchr(*temp, '\n'))
	{
		*dest_line = ft_strdup(*temp);
		free(*temp);
		return (0);
	}
	*dest_line = ft_strtoken_w_o_delim(*temp, '\n');
	if (!*dest_line)
		return (ft_errors(temp, -2));
	len = ft_strlen(strchr(*temp, '\n'));
	ft_memmove(*temp, (strchr(*temp, '\n') + 1), len);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	ssize_t		r_value;
	static char	*temp = "";
	char		buf[BUFF_SIZE + 1];
	char		*free_er;

	r_value = BUFF_SIZE;
	while (!strchr(temp, '\n') && r_value == BUFF_SIZE)
	{
		r_value = read(fd, &buf, BUFF_SIZE);
		if (r_value == -1)
			return (ft_errors(&temp, -1));
		buf[r_value] = '\0';
		free_er = temp;
		temp = ft_strjoin (temp, buf);
		if (!temp)
			return (ft_errors(&temp, -2));
		free(free_er);
	}
	return (ft_cpy(line, &temp));
}
