/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:27:12 by adrossig          #+#    #+#             */
/*   Updated: 2022/04/14 16:58:30 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Frees the memory allocated for a list.
 *
 * @param lst The list to free.
 * @param del The function to call to free the content of the list.
 *
 * @returns None
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
