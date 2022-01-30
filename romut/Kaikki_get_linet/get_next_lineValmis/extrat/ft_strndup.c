/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <koykka.atte@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:01:37 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/04 22:27:12 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*fresh;

	fresh = (char *)malloc(sizeof(char) * (n + 1));
	if (!fresh)
		return (NULL);
	ft_strncpy(fresh, (char *)s1, n)[n] = '\0';
	return (fresh);
}
