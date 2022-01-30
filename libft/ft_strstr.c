/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:40:54 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/06 21:44:05 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	n;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{	
		n = 0;
		while (needle[n] == haystack[n])
		{
			n++;
			if (!needle[n])
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
