/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:38 by arossign          #+#    #+#             */
/*   Updated: 2022/04/09 13:24:52 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_2d(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
	{
		free(strs[i]);
		strs[i] = NULL;
	}
	free(strs);
	strs = NULL;
}

void	free_res(t_collect *var)
{
	free_2d(var->cmd);
	free_2d(var->paths);
	free(var->slash_cmd);
	var->slash_cmd = NULL;
}

void	exit_error(t_collect *var, char *short_cmd, char *msg, int exit_code)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(short_cmd, STDERR_FILENO);
	if (!msg)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
	else
		ft_putendl_fd(msg, STDERR_FILENO);
	free_res(var);
	free(short_cmd);
	exit (exit_code);
}
