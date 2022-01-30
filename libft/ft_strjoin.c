/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <koykka.atte@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:37:56 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/03 20:32:45 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fresh)
		return (NULL);
	while (*s1)
	{
		fresh[i] = *s1;
		++i;
		++s1;
	}
	while (*s2)
	{
		fresh[i] = *s2;
		++i;
		++s2;
	}
	fresh[i] = '\0';
	return (fresh);
}
