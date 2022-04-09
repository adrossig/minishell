/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:57:28 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:27:34 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Gets the element label for a given string.
 *
 * @param dict The dictionary to search.
 * @param string The string to search for.
 *
 * @returns The element label for the string, or 
 * NULL if the string is not in the dictionary.
 */
void	*ft_get_element_label(t_dictionary *dict, char *string)
{
	int	index;

	index = ft_gethash(string);
	if (dict->elements[index])
		return (dict->elements[index]);
	return (NULL);
}
