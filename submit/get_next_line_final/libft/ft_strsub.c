/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:40:47 by akoykka           #+#    #+#             */
/*   Updated: 2022/01/06 14:33:10 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (len--)
	{
		substring[i] = s[start];
		++i;
		++start;
	}
	substring[i] = '\0';
	return (substring);
}
