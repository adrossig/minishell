/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:37 by arossign          #+#    #+#             */
/*   Updated: 2022/03/28 16:13:45 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **args)
{
	int	i;
	int	j;
	int	new_l;

	i = 0;
	new_l = 0;
	while (args[i] && !ft_strncmp(args[i], "-n", 2))
	{
		j = 1;
		while (args[i][j] && args[i][j] == 'n')
			j++;
		if (args[i][j] && args[i][j] != 'n')
			break ;
		new_l++;
		i++;
	}
	while (args && args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!new_l)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
