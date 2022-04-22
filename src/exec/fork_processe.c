/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_processe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:24:40 by arossign          #+#    #+#             */
/*   Updated: 2022/04/16 20:16:43 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	arrange_return(t_list *cmds, int stdin_dup)
{
	dup2(stdin_dup, STDIN_FILENO);
	ft_lstclear(&cmds, NULL);
	unlink(".heredoc.tmp");
	check_empty_line();
}

int	check_error(char *cmd, char **envp)
{
	char	**paths;
	char	**args;
	char	*full_cmd;
	char	*slash_cmd;
	int		i;

	if (!access(cmd, F_OK | X_OK))
		return (0);
	i = 0;
	args = ft_split(cmd, ' ');
	cmd = args[0];
	slash_cmd = ft_strjoin("/", cmd);
	free_2d(args);
	paths = ft_split(ft_getenv("PATH=", envp), ':');
	while (paths && paths[i])
	{
		full_cmd = ft_strjoin(paths[i], slash_cmd);
		if (!access(full_cmd, F_OK))
			return (free(full_cmd), free(slash_cmd), free_2d(paths), 0);
		free(full_cmd);
		i++;
	}
	return (free(slash_cmd), free_2d(paths), 1);
}

int	execute_fork(char *cmd, t_utils *utils_, char **envp, t_exit *exit_)
{
	int		fd[2];
	pid_t	pid_child;
	int		r_builtin;

	if (fork_here_doc(cmd, utils_->stdin_dup, envp, exit_))
		return (1);
	if (pipe(fd) != 0)
		return (perror("minishell: pipe"), 1);
	pid_child = fork();
	if (pid_child == -1)
		return (perror("minishell: fork"), 1);
	else if (!pid_child)
	{
		utils_->fd = fd[1];
		r_builtin = check_builtin(cmd, utils_, envp, exit_);
		if (!r_builtin)
			fork_child_1(cmd, utils_->stdin_dup, fd, envp);
		exit_builtin(r_builtin);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	if (check_error(cmd, envp))
		waitpid(pid_child, NULL, 0);
	return (0);
}

void	fork_processes(t_list *cmds, char **envp, t_exit *exit_)
{
	t_list	*hol;
	t_utils	utils_;
	pid_t	pid_child;
	int		status;

	hol = cmds;
	if (!cmds)
		return ;
	utils_.stdin_dup = dup(STDIN_FILENO);
	while (cmds->next)
	{
		if (execute_fork(cmds->content, &utils_, envp, exit_))
			return (arrange_return(hol, utils_.stdin_dup));
		exit_->exit_pipe += 1;
		cmds = cmds->next;
	}
	utils_.fd = STDOUT_FILENO;
	if (!check_builtin(cmds->content, &utils_, envp, exit_))
	{
		pid_child = fork();
		if (!pid_child)
			fork_child_2(cmds->content, utils_.stdin_dup, envp, exit_);
		get_exit_code(pid_child, &status, exit_);
	}
	arrange_return(hol, utils_.stdin_dup);
}
