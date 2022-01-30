/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:09:29 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/15 14:51:18 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_dup_w_o_newline(char *str)
{
	size_t	i;
	char	*token;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	token = ft_strndup(str, i - 1 );
	return (token);
}

static void	ft_copy(char **dest_line, char **src_buf, int r_value)
{
	char	*free_er;

	if (r_value < BUFF_SIZE && strchr(&buf, '\n'))
	{
		&dest_line = ft_strjoin(&dest_line, ft_strdup(&src_buf))
		if (!&dest_line)
		{
			ft_putstr_fd("Malloc Error\n", 2);
			ft_strdel(&dest);
			return (NULL);
		}
		return (0);
	}
	&dest_line = ft_strjoin(&dest_line, ft_dup_w_o_newline(&buf));
	if (!&dest_line)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		ft_strdel(&dest_line);
		return (NULL);
	}
	return (1);
}

static void ft_cpy_and_reset_buf(char *buf char **line)
{
	&line = ft_dup_w_o_newline(&buf);
	memset(&buf, (BUFF_SIZE + 1);
}

int	get_next_line(const int fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = "";
	int				r_value;

	r_value is default something
	&line = ft_strnew(1);
	//ft_cpyandresetbuf(&buf, char** line);
	//r_value = read(fd, &buf, BUFF_SIZE);
	while (r_value != -1)
	{
		if (!*ft_strchr(&buf, '\n') && r_value == BUFF_SIZE)
		{
			if (ft_copy(&line, &buf, r_value) == NULL)
			{
				ft_putstr_fd("Malloc Error\n", 2);
				return (-1);
			}
		}
		else
		{
			if (ft_copy(&line, &buf, &temp, r_value) == NULL)
			{
				ft_putstr_fd("Malloc Error\n", 2);
				return (-1);
			}
		}
		r_value = read(fd, &buf, BUFF_SIZE);
	}
	ft_putstr_fd("Read Error\n", 2);
	return (-1);
}