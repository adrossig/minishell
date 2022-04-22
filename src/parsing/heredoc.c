/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:42 by arossign          #+#    #+#             */
/*   Updated: 2022/04/20 15:19:00 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*change_cmd_here_doc(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		i += check_quotes(&cmd[i]);
		if (cmd[i] == '<' && cmd[i + 1] == '<')
			cmd[i + 2] = 0;
		i++;
	}
	return (cmd);
}

int	create_heredoc_file(t_list *strs_holder)
{
	int		fd_in;
	int		infile_flags;
	mode_t	infile_perms;

	infile_flags = O_TRUNC | O_CREAT | O_WRONLY;
	infile_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd_in = open(".heredoc.tmp", infile_flags, infile_perms);
	if (fd_in < 0)
		return (ft_putstr_fd("here_doc", STDERR_FILENO), perror (" \b"), 0);
	while (strs_holder)
	{
		ft_putstr_fd(strs_holder->content, fd_in);
		ft_putstr_fd("\n", fd_in);
		free(strs_holder->content);
		strs_holder = strs_holder->next;
	}
	close(fd_in);
	return (1);
}

int	discover_if_there_are_quotes(char *limiter)
{
	int	quotes;

	if (ft_strchr(limiter, '\'') || ft_strchr(limiter, '"'))
		quotes = 1;
	else
		quotes = 0;
	return (quotes);
}

char	*here_doc(char *limiter, int stdin_no, char **envp, t_exit *exit_)
{
	t_list	*strs_holder;
	char	*line;
	int		quotes;

	strs_holder = NULL;
	dup2(stdin_no, STDIN_FILENO);
	unlink(".heredoc.tmp");
	quotes = discover_if_there_are_quotes(limiter);
	remove_quotes_1d(limiter);
	while (1)
	{
		g_sig_indice = -1;
		line = readline_config("heredoc> ");
		if (!line || (!ft_strncmp(line, limiter, ft_strlen(limiter))
				&& line[ft_strlen(limiter)] == '\0'))
			break ;
		if (!quotes)
			line = expand_dollar_s_heredoc(ft_strdup(line), envp, exit_);
		ft_lstadd_back(&strs_holder, ft_lstnew(line));
	}
	if (!create_heredoc_file(strs_holder))
		return (ft_lstclear(&strs_holder, NULL), NULL);
	ft_lstclear(&strs_holder, NULL);
	return (ft_strdup(".heredoc.tmp"));
}

void	get_here_doc_input(char *cmd, int stdin_dp, char **envp, t_exit *exit_)
{
	int	i;
	int	hol;

	i = 0;
	hol = -1;
	while (cmd[i])
	{
		i += check_quotes(&cmd[i]);
		if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			if (hol != -1)
				to_space(cmd, hol, 2);
			hol = i;
			here_doc(file_io_name_2(&cmd[i + 2], 1), stdin_dp, envp, exit_);
		}
		i++;
	}
}
