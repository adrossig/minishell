/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:48 by arossign          #+#    #+#             */
/*   Updated: 2022/04/19 18:07:23 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export_check_single(char *name, int len, bool plus, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], name, len - plus - 1))
			return (free((name - plus)), 1);
	return (free((name - plus)), 0);
}

void	export_change_value(char **envp, int len, bool plus, char *var)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(*envp);
	free(*envp);
	if (plus)
	{
		if (!ft_strchr(tmp, '='))
		{
			tmp2 = ft_strjoin(tmp, "=");
			*envp = ft_strjoin(tmp2, &var[len]);
			free(tmp2);
		}
		else
			*envp = ft_strjoin(tmp, &var[len]);
	}
	else
		*envp = ft_strdup(var);
	free(tmp);
}

void	put_envp(char *envp)
{
	int		i;
	bool	one;

	i = 0;
	one = 0;
	if (!envp)
		return ;
	while (envp[i])
	{
		ft_putchar_fd(envp[i], STDOUT_FILENO);
		if (!one && envp[i] == '=')
		{
			ft_putchar_fd('"', STDOUT_FILENO);
			one = 1;
		}
		i++;
	}
	if (ft_strchr(envp, '='))
		ft_putendl_fd("\"", STDOUT_FILENO);
	else
		ft_putendl_fd("", STDOUT_FILENO);
}

void	print_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		put_envp(envp[i]);
		i++;
	}
}

void	check_plus(char **var)
{
	int		i;
	char	*hol;

	i = 0;
	while (var[0] && var[0][i] && var[0][i] != '=')
		i++;
	if (var[0] && var[0][i - 1] == '+')
	{
		while (--i > 0)
			var[0][i] = var[0][i - 1];
		hol = ft_strdup(&var[0][1]);
		free(var[0]);
		var[0] = hol;
	}
}
