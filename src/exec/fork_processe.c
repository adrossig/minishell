/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_processe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:24:40 by arossign          #+#    #+#             */
/*   Updated: 2022/03/28 16:39:54 by arossign         ###   ########.fr       */
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

int	execute_fork(char *cmd, int stdin_dup, char **envp)
{
	int		fd[2];
	pid_t	pid_child;
	int		r_builtin;

	if (fork_here_doc(cmd, stdin_dup))
		return (1);
	if (pipe(fd) != 0)
		return (perror("minishell: pipe"), 1);
	pid_child = fork();
	if (pid_child == -1)
		return (perror("minishell: fork"), 1);
	else if (!pid_child)
	{
		r_builtin = check_builtin(cmd, stdin_dup, fd[1], envp);
		if (!r_builtin)
			fork_child_1(cmd, stdin_dup, fd, envp);
		exit_builtin(r_builtin);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	if (check_error(cmd, envp))
		waitpid(pid_child, NULL, 0);
	return (0);
}

void	fork_processes(t_list *cmds, char **envp)
{
	t_list	*hol;
	pid_t	pid_child;
	int		stdin_dup;
	int		status;

	hol = cmds;
	if (!cmds)
		return ;
	stdin_dup = dup(STDIN_FILENO);
	while (cmds->next)
	{
		if (execute_fork(cmds->content, stdin_dup, envp))
			return (arrange_return(hol, stdin_dup));
		cmds = cmds->next;
	}
	if (!check_builtin(cmds->content, stdin_dup, STDOUT_FILENO, envp))
	{
		pid_child = fork();
		if (!pid_child)
			fork_child_2(cmds->content, stdin_dup, envp);
		get_exit_code(pid_child, &status);
	}
	arrange_return(hol, stdin_dup);
}
