/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:01:53 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:20:22 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Destroys a dictionary.
 *
 * @param dict The dictionary to destroy.
 *
 * @returns None
 */
void	ft_destroy(t_dictionary *dict)
{
	free(dict);
}
