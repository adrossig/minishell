/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:26:22 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/30 16:20:01 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Adds a new element to the end of a list.
 *
 * @param alst The list to add the new element to.
 * @param new The new element to add to the list.
 *
 * @returns None
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}
