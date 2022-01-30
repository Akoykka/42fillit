/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <koykka.atte@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:01:37 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/03 20:28:53 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (len > i)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
