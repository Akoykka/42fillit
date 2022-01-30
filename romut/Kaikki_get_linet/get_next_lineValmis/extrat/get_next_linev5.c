/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:28:16 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/15 16:02:07 by akoykka          ###   ########.fr       */
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
	token = ft_strndup(str, i - 1);
	return (token);
}

static void	ft_cpyend(char **dest_line, char *src_buf, char **temp, int r_value)
{
	char	*free_er;
	char	*free_er2;

	if (r_value < BUFF_SIZE)
	{
		
		&dest = ft_strjoin(&temp, ft_strdup(&temp)
		kopioi kaikki
		free(&temp)
		return (0)
	}

	free_er = &temp;
	free_er2 = ft_strtoken(src_buf);
	&dest_line = ft_strjoin(&temp, free_er2);
	free(free_er);
	free(free_er2);
	return (1);
}

static void	ft_copymore(char **dest_temp, char **src_buf, int r_value)
{
	char *free_er;

	dest = ft_strjoin(&source, ft_strtoken(&src_buf, &temp));
	if (!dest)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		ft_strdel(&dest);
		return (NULL);
	}
}

int	get_next_line(const int fd, char **line)
{
	int 		r_value;
	static char *temp = "";
	char		buf[BUFF_SIZE + 1];
	char		*free_er;

	if (!fd)
		ft
	r_value = read(fd, &buf, BUFF_SIZE);
	while (r_value != -1)
	{
		if (!*ft_strchr(&buf,'\n') && r_value == BUFF_SIZE)
		{
			ft_copymore(&temp, &buf, r_value);
		}
		else
		{
			ft_copyend(&line, &buf, &temp, r_value);
			return (0);
		}
		r_value = read(fd, &buf, BUFF_SIZE);
	}
	ft_putstr_fd("Read Error\n", 2);
	return(-1);
}

