/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:03:44 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/08 14:39:05 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
		++i;
	}
	return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
}
