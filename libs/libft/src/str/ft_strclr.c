/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:36:29 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:51:02 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Clears a string.
 *
 * @param s The string to clear.
 *
 * @returns None
 */
void	ft_strclr(char *s)
{
	size_t	size;

	size = ft_strlen(s);
	while (size--)
		*(s + size) = '\0';
}
