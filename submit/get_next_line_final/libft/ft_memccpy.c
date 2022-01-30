/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:05:23 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/08 15:46:52 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		if (((const unsigned char *)src)[i] == (unsigned char)c)
			return (&dst[i + 1]);
		++i;
	}
	return (NULL);
}
