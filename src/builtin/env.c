/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:41 by arossign          #+#    #+#             */
/*   Updated: 2022/04/18 17:49:27 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **args, char **envp, t_exit *exit_)
{
	int	i;

	i = 0;
	if (args && args[0])
	{
		ft_putstr_fd("env: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putendl_fd(ERR_ARGS, STDERR_FILENO);
		exit_->exit_code = 127;
		return ;
	}
	while (envp[i])
	{
		if (ft_strchr(envp[i], '='))
			ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
}
