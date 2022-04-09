/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_armstrong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:09:33 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:36:46 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Computes the power of a number.
 *
 * @param base The base of the power.
 * @param exponent The exponent of the power.
 *
 * @returns The power of the base to the exponent.
 */
void	ft_armstrong(int num)
{
	int		original_num;
	int		remainder;
	int		i;
	float	result;

	i = 0;
	result = 0.0;
	original_num = num;
	while (original_num != 0)
	{
		original_num /= 10;
		++i;
	}
	original_num = num;
	while (original_num != 0)
	{
		remainder = original_num % 10;
		result += ft_power(remainder, i);
		original_num /= 10;
	}
	if ((int)result == num)
		ft_putstr("Is an Armstrong number.");
	else
		ft_putstr("Is not an Armstrong number.");
}
