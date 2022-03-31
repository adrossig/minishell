/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:38:00 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:57:30 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Frees a string array.
 *
 * @param str The string array to free.
 *
 * @returns None
 */
char	**ft_strfree(char **str)
{
	while (*str)
	{
		free(*str);
		(*str)++;
	}
	free(str);
	return (NULL);
}
