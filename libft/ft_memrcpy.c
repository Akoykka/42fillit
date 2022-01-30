/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:35:38 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/06 21:44:11 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		n = 0;
	while (n--)
		((unsigned char *)dst)[n] = ((const unsigned char *)src)[n];
	return (dst);
}
