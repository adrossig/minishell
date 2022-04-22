/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:52 by arossign          #+#    #+#             */
/*   Updated: 2022/04/20 14:33:40 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_envp(char *var, char **envp)
{
	int		i;
	char	*hol;

	i = 0;
	while (envp[i])
	{
		hol = ft_strnstr(envp[i], var, ft_strlen(var));
		if (hol && (envp[i][ft_strlen(var)] == '=' || !ft_strchr(envp[i], '=')))
		{
			free(envp[i]);
			while (envp[i])
			{
				envp[i] = envp[i + 1];
				i++;
			}
			return ;
		}
		i++;
	}
}

int	check_val_identiers(char *str, t_exit *exit_)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			ft_putendl_fd(UNSET_ARG, STDERR_FILENO);
			return (exit_->exit_code = 1, 1);
		}
		i++;
	}
	return (0);
}

void	ft_unset(char **args, char **envp, t_exit *exit_)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!check_val_identiers(args[i], exit_)
			&& !check_num_arg(args[i][0], UNSET_ARG, exit_))
			unset_envp(args[i], envp);
		i++;
	}
}
