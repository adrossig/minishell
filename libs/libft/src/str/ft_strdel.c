/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:17 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:51:19 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Frees the memory allocated for a string.
 *
 * @param as The string to free.
 *
 * @returns None
 */
void	ft_strdel(char **as)
{
	if (*as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
