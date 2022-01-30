/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:55:24 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/07 22:05:58 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;
	int		i;

	i = 0;
	fresh = (void *)malloc(size);
	if (!fresh)
		return (NULL);
	while (size--)
	{
		((unsigned char *)fresh)[i] = 0;
		++i;
	}
	return (fresh);
}
