/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:41:15 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:27:47 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Creates a dictionary.
 *
 * @returns A pointer to the dictionary.
 */
t_dictionary	*create_dict(void)
{
	t_dictionary	*locma;
	int				i;

	locma = malloc(sizeof(t_dictionary));
	if (!(locma))
		return (NULL);
	else
	{
		locma->nbr = 0;
		i = 0;
		while (i < MAXELEMENTS)
		{
			locma->elements[i] = NULL;
			i++;
		}
		return (locma);
	}
}
