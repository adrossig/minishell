/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:25:38 by adrossig          #+#    #+#             */
/*   Updated: 2022/03/30 14:37:45 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	void	ft_fill(char *snum, long n, int i)
{
	int	j;

	j = 0;
	snum[i--] = '\0';
	if (n < 0)
	{
		j = 1;
		n = -n;
	}
	while (i > j)
	{
		snum[i--] = "0123456789"[n % 10];
		n /= 10;
	}
	snum[i] = "0123456789"[n];
}

static	int	ft_count(long m)
{
	int	i;

	i = 0;
	if (m < 0)
	{
		m = -m;
		i++;
	}
	while (m > 9)
	{
		m /= 10;
		i++;
	}
	return (i);
}

/**
 * Converts an integer to a string.
 *
 * @param n The integer to convert.
 *
 * @returns The string representation of the integer.
 */
char	*ft_itoa(int n)
{
	int		i;
	char	*snum;
	long	m;

	i = 1;
	m = (long)n;
	i = ft_count(m);
	snum = (char *)malloc(sizeof(char) * (i + 2));
	if (snum == NULL)
		return (NULL);
	if (n < 0)
		snum[0] = '-';
	ft_fill(snum, m, i + 1);
	return (snum);
}
