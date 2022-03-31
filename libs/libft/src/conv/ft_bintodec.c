/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:06 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 22:57:23 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_bintodec(int binary)
{
	int	i;
	int	mult;

	i = 0;
	mult = 1;
	while (binary != 0)
	{
		i += (binary % 10) * mult;
		binary /= 10;
		mult *= 2;
	}
	return (i);
}
