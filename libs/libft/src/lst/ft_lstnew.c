/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:29:22 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:36:12 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Creates a new list element.
 *
 * @param content The content of the new list element.
 *
 * @returns The new list element.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = NULL;
	liste = malloc(sizeof(t_list));
	if (!(liste))
		return (NULL);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}

/**
 * Creates a new list node.
 *
 * @param content The content of the new node.
 * @param content_size The size of the content.
 *
 * @returns The new list node.
 */
t_list	*ft_lstnnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(content_size);
		if (!new->content)
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
