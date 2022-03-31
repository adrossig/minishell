/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:02:33 by arossign          #+#    #+#             */
/*   Updated: 2022/02/11 23:00:35 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Converts a long long integer to a string.
 *
 * @param n The long long integer to convert.
 *
 * @returns The string representation of the long long integer.
 */
char	*ft_lltoa(long long n)
{
	return (ft_lltoa_base(n, "0123456789"));
}
