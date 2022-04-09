/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:33:44 by arossign          #+#    #+#             */
/*   Updated: 2022/04/08 13:37:56 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	which_builtin(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	cmd = args[0];
	remove_quotes_1d(cmd);
	if (!ft_strncmp(cmd, "export", 6) && ft_strlen(cmd) == 6)
		return (free_2d(args), 4);
	else if (!ft_strncmp(cmd, "unset", 5) && ft_strlen(cmd) == 5)
		return (free_2d(args), 5);
	else if (!ft_strncmp(cmd, "exit", 4) && ft_strlen(cmd) == 4)
		return (free_2d(args), 7);
	ft_tolower_str(cmd);
	if (!ft_strncmp(cmd, "echo", 4) && ft_strlen(cmd) == 4)
		return (free_2d(args), 1);
	else if (!ft_strncmp(cmd, "cd", 2) && ft_strlen(cmd) == 2)
		return (free_2d(args), 2);
	else if (!ft_strncmp(cmd, "pwd", 3) && ft_strlen(cmd) == 3)
		return (free_2d(args), 3);
	else if (!ft_strncmp(cmd, "env", 3) && ft_strlen(cmd) == 3)
		return (free_2d(args), 6);
	else
		return (free_2d(args), 0);
}

int	builtin_io(char *cmd, int stdin_dup, t_exit *exit_)
{
	int	r_io;

	r_io = 0;
	exit_->exit_code = 0;
	if (fork_here_doc(cmd, stdin_dup, exit_))
		return (0);
	while (r_io != -1)
	{
		r_io = get_io_files(cmd, stdin_dup);
		if (r_io == -2)
			return (exit_->exit_code = 1, 0);
	}
	return (1);
}

int	execute_builtin(char *cmd, t_utils *utils_, char **envp, t_exit *exit_)
{
	char	**args;
	int		stdout_dup;

	if (!utils_->builtin_iden)
		return (0);
	stdout_dup = dup(STDOUT_FILENO);
	if (utils_->builtin_iden != 7 && !builtin_io(cmd, utils_->stdin_dup, exit_))
		return (-1);
	args = ft_split(cmd, ' ');
	remove_quotes_2d(&args[1]);
	if (utils_->builtin_iden == 1)
		ft_echo(&args[1]);
	else if (utils_->builtin_iden == 2)
		ft_cd(&args[1], envp, exit_);
	else if (utils_->builtin_iden == 3)
		ft_pwd(&args[1], exit_);
	else if (utils_->builtin_iden == 4)
		ft_export(&args[1], envp, exit_);
	else if (utils_->builtin_iden == 5)
		ft_unset(&args[1], envp, exit_);
	else if (utils_->builtin_iden == 6)
		ft_env(&args[1], envp, exit_);
	else if (utils_->builtin_iden == 7)
		ft_exit(&args[1], envp, exit_);
	return (dup2(stdout_dup, STDOUT_FILENO), free_2d(args), 1);
}

int	builtin_name(char *cmd, int fd)
{
	int	builtin_iden;

	if (cmd && cmd[0])
	{
		builtin_iden = which_builtin(cmd);
		if (builtin_iden)
			dup2(fd, STDOUT_FILENO);
		return (builtin_iden);
	}
	return (0);
}

int	check_builtin(char *cmd, t_utils *utils_, char **envp, t_exit *exit_)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (cmd[i] && (cmd[i] == '<' || cmd[i] == '>'))
		{
			while (cmd[i] && (cmd[i] == '<' || cmd[i] == '>'
					|| cmd[i] == ' '))
				i++;
			while (cmd[i] && cmd[i] != ' ')
				i++;
		}
		else
			break ;
	}
	utils_->builtin_iden = builtin_name(&cmd[i], utils_->fd);
	if (utils_->builtin_iden)
		return (execute_builtin(cmd, utils_, envp, exit_));
	return (0);
}
