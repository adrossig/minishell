/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:37:08 by ltorrean          #+#    #+#             */
/*   Updated: 2022/04/20 14:38:02 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit_skip_spaces_e_quote(char **args)
{
	int	j;

	j = 0;
	while (args && args[0] && args[0][j] == ' ')
		j++;
	if (args && args[0] && args[0][j] == '"')
		j++;
	return (j);
}

int	is_numeric_argument_required(char *str, char sign, int number)
{
	unsigned long long	i;
	unsigned long long	res;
	int					count;

	res = 0;
	i = 0;
	if (!str)
		return (0);
	count = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = 1;
		res = (10 * res) + (str[i] - '0');
		i++;
	}
	count = i - count ;
	if (str[i] && str[i] == '"')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if ((str[i] != 0) || count > 19 || !number
		|| (res > 9223372036854775808ULL && sign == '-')
		|| (res > LLONG_MAX && sign != '-'))
		return (1);
	return (0);
}
