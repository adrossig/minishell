/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:00:07 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:26:08 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Gets an element from a dictionary.
 *
 * @param dict The dictionary to get the element from.
 * @param index The index of the element to get.
 *
 * @returns The element at the given index, or 
 * NULL if the index is out of bounds.
 */
void	*ft_get_element_index(t_dictionary *dict, int index)
{
	if (index >= 0 && index < MAXELEMENTS)
		return (dict->elements[index]);
	return (NULL);
}
