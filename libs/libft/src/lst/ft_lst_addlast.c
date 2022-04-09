/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:54:59 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:29:25 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Adds a new element to the end of a linked list.
 *
 * @param head The head of the linked list.
 * @param last The new element to add to the end of the linked list.
 *
 * @returns None
 */
void	ft_lst_addlast(t_list **head, t_list *last)
{
	if (!last || !head)
		return ;
	if (!(*head))
		*head = last;
	else
		ft_lst_addlast(&((*head)->next), last);
}
