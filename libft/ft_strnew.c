/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <koykka.atte@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:30:09 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/03 18:21:00 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (size--)
	{
		ptr[i] = '\0';
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
