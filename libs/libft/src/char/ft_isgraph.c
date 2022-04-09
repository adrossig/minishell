/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:23:56 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Checks if a character is a printable character.
 *
 * @param c The character to check.
 *
 * @returns 1 if the character is printable, 0 otherwise.
 */
int	ft_isgraph(int c)
{
	if ((c >= 32 && c <= 126) && !(c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (MY_OK);
}
