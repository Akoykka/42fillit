/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:03:32 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/13 11:29:13 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
	{
		if (!s1[i] || !s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		++i;
	}
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
