/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:47 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/29 12:10:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Compares two strings for equality.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @returns 1 if the strings are equal, 0 otherwise.
 */
int	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (KO);
	if (!ft_strcmp(s1, s2))
		return (1);
	else
		return (MY_OK);
}
