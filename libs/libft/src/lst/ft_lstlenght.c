/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:40:09 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:34:09 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the length of a linked list.
 *
 * @param list The linked list.
 *
 * @returns The length of the linked list.
 */
size_t	ft_lstlenght(t_list *list)
{
	unsigned int	lenght;

	lenght = 0;
	while (list != NULL)
	{
		++lenght;
		list = list->next;
	}
	return (lenght);
}
