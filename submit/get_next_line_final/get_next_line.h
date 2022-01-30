/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 01:22:10 by akoykka           #+#    #+#             */
/*   Updated: 2022/01/06 22:22:49 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define BUFF_SIZE 8

int		get_next_line(const int fd, char **line);
#endif