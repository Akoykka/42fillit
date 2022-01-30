/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:12:36 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/06 21:44:18 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		found;
	char	*lastseen;

	found = 0;
	while (*s != '\0')
	{
		if (c == *s)
		{
			lastseen = (char *) s;
			found = 1;
		}
		++s;
	}
	if (c == 0)
		return ((char *) s);
	if (found == 1)
		return (lastseen);
	return (NULL);
}
