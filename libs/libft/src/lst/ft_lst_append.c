/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:53:08 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:29:33 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Appends a list to another list.
 *
 * @param head The head of the list to append to.
 * @param last The list to append.
 *
 * @returns The head of the list.
 */
t_list	*ft_lstappend(t_list *head, t_list *last)
{
	t_list	*current;

	current = head;
	if (!current)
		return (last);
	while (current->next)
		current = current->next;
	current->next = last;
	return (head);
}
