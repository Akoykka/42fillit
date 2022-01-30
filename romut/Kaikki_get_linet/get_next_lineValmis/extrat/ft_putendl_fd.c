/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <koykka.atte@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:03:42 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/03 23:17:01 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	i;

	if (!fd || !s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
	write(fd, "\n", 1);
}
