/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylst_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:31:46 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 22:56:12 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Frees the memory allocated for an arraylist.
 *
 * @param arraylist The arraylist to free.
 *
 * @returns None
 */
void	ft_arraylst_free(t_array *arraylist)
{
	if (arraylist != NULL)
	{
		free(arraylist->data);
		free(arraylist);
	}
}
