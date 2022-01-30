/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:32:49 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/06 20:02:21 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dst && !src)
		n = 0;
	while (n--)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		++i;
	}
	return (dst);
}
