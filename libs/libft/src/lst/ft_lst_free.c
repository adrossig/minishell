/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:57:42 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:30:10 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Frees a list.
 *
 * @param list The list to free.
 * @param content_free The function to free the content of the list.
 *
 * @returns None
 */
void	ft_lst_free(t_list **list, void (*content_free)(void **))
{
	if (!list || !*list || !content_free)
		return ;
	if (!(*list)->next)
	{
		(*content_free)(&((*list)->content));
		ft_memdel((void **)(list));
	}
	else
	{
		ft_lst_free(&((*list)->next), content_free);
		(*content_free)(&((*list)->content));
		ft_memdel((void **)(list));
	}
}

/**
 * Frees a list of elements that match a condition.
 *
 * @param plst The list to free.
 * @param cond The condition to match.
 * @param data The data to match.
 * @param c_free The function to free the matched element.
 *
 * @returns None
 */
void	ft_lst_free_if(t_list **plst, int (*cond)(void*, void*),
		void *data, void (*c_free)(void**))
{
	t_list	*head;

	if (!plst || !*plst || !c_free || !cond || !data)
		return ;
	if ((*cond)(data, (*plst)->content))
	{
		head = (*plst)->next;
		(*c_free)(&(*plst)->content);
		ft_memdel((void **)plst);
		*plst = head;
	}
	else
		ft_lst_free_if(&(*plst)->next, cond, data, c_free);
}

/**
 * Frees a list of elements that match a condition.
 *
 * @param plst The list to free.
 * @param cond The condition to match.
 * @param c_free The function to call to free the content of the list.
 *
 * @returns None
 */
void	ft_lst_freeif(t_list **plst, int (*cond)(void*),
		void (*c_free)(void **))
{
	t_list	*head;

	if (!plst || !*plst || !c_free || !cond)
		return ;
	if ((*cond)((*plst)->content))
	{
		head = (*plst)->next;
		(*c_free)(&(*plst)->content);
		ft_memdel((void **)plst);
		*plst = head;
	}
	else
		ft_lst_freeif(&(*plst)->next, cond, c_free);
}
