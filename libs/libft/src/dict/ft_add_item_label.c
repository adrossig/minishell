/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_item_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:53:16 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Adds an item to the dictionary.
 *
 * @param dict The dictionary to add the item to.
 * @param label The label to add the item to.
 * @param item The item to add to the dictionary.
 *
 * @returns OK if the item was added to the dictionary, KO otherwise.
 */
int	ft_add_item_label(t_dictionary *dict, char *label, void *item)
{
	unsigned int	index;

	index = ft_gethash(label);
	if (index < MAXELEMENTS)
	{
		dict->elements[index] = item;
		return (MY_OK);
	}
	return (KO);
}
