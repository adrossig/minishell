/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:53:49 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:47:31 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Sorts an array of integers using the bubble sort algorithm.
 *
 * @param a The array to sort.
 * @param b The size of the array.
 *
 * @returns None
 */
void	ft_bubblesort(int *a, int b)
{
	int	i;
	int	j;

	i = 0;
	while (i < b - 1)
	{
		j = 0;
		while (j < ((b - i) - 1))
		{
			if (*(a + j) > *(a + j + 1))
				ft_swap(&a[j], &a[j + 1]);
			j++;
		}
		i++;
	}
}
