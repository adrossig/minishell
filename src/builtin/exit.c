/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:45 by arossign          #+#    #+#             */
/*   Updated: 2022/04/20 14:35:40 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_minishell_ctrl_d_utils(void)
{
	char	s[PATH_MAX];
	char	buff[PATH_MAX];

	s[0] = 0;
	ft_strcpy(s, "\033[1A\033[");
	if (getcwd(buff, sizeof(buff)) == NULL)
		ft_putendl_fd("\033[1A\033[10Cexit", STDOUT_FILENO);
	else
	{
		ft_strcat(s, ft_itoa(ft_strlen(ft_strrchr(buff, '/') + 1) + 4));
		ft_strcat(s, "Cexit");
		ft_putendl_fd(s, STDOUT_FILENO);
	}
}

void	free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		free(envp[i++]);
}

void	exit_minishell_ctrl_d(char **envp, t_exit *exit_)
{
	if (tgetstr("cm", NULL))
	{
		if (ft_getenv("HOME=", envp) && ft_getenv("PWD=", envp)
			&& !ft_strcmp(ft_getenv("PWD=", envp), ft_getenv("HOME=", envp)))
			ft_putendl_fd("\033[1A\033[5Cexit", STDOUT_FILENO);
		else
			exit_minishell_ctrl_d_utils();
	}
	else
		ft_putendl_fd("exit", STDOUT_FILENO);
	free_envp(envp);
	exit(exit_->exit_code);
}

void	ft_exit_assign_exit_shell(char **args, t_exit *exit_)
{
	if (args && args[0] && args[1])
		return (exit_->exit_code = 1, ft_putendl_fd(ERR_EXIT_NUM, 2));
	if (exit_->exit_pipe == 1)
	{
		if (args[0])
			exit_->exit_shell = ((unsigned char)ft_atoi(args[0]));
		else
			exit_->exit_shell = exit_->exit_code;
	}
	else
		if (args[0])
			exit_->exit_code = ((unsigned char)ft_atoi(args[0]));
}

void	ft_exit(char **args, char **envp, t_exit *exit_)
{
	int		j;
	int		res;
	char	sign;
	int		number;

	sign = 'M';
	number = 0;
	if (exit_->exit_pipe == 1)
		ft_putendl_fd("exit", STDOUT_FILENO);
	j = ft_exit_skip_spaces_e_quote(args);
	if (args && args[0] && (args[0][j] == '-' || args[0][j] == '+'))
		sign = args[0][j++];
	res = is_numeric_argument_required(&args[0][j], sign, number);
	if (res == 1)
	{
		if (exit_->exit_pipe == 1)
			return (exit_->exit_shell = 255, free_envp(envp),
				ft_putendl_fd(ERR_EXIT_ARG, STDERR_FILENO));
		else
			return (exit_->exit_code = 255,
				ft_putendl_fd(ERR_EXIT_ARG, STDERR_FILENO));
	}
	ft_exit_assign_exit_shell(args, exit_);
}
