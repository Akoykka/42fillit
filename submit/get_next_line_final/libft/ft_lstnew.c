/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:17:31 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/08 15:28:33 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	fresh->next = NULL;
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		return (fresh);
	}
	fresh->content = (void *)malloc(content_size);
	if (!fresh->content)
	{
		free(fresh);
		return (NULL);
	}
	ft_memcpy(fresh->content, content, content_size);
	fresh->content_size = content_size;
	return (fresh);
}
