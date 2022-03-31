/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:42 by arossign          #+#    #+#             */
/*   Updated: 2022/03/30 17:01:20 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

char	*here_doc(char *limiter, int stdin_no)
{
	t_list	*strs_holder;
	char	*line;

	strs_holder = NULL;
	dup2(stdin_no, STDIN_FILENO);
	unlink(".heredoc.tmp");
	while (1)
	{
		g_vars.sig_indice = -1;
		line = readline_config("heredoc> ");
		if (!line || (!ft_strncmp(line, limiter, ft_strlen(limiter))
				&& line[ft_strlen(limiter)] == '\0'))
			break ;
		ft_lstadd_back(&strs_holder, ft_lstnew(line));
	}
	if (!create_heredoc_file(strs_holder))
		return (ft_lstclear(&strs_holder, NULL), NULL);
	ft_lstclear(&strs_holder, NULL);
	return (ft_strdup(".heredoc.tmp"));
}

void	get_here_doc_input(char *cmd, int stdin_dup)
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
			here_doc(file_io_name(&cmd[i + 2], 1), stdin_dup);
		}
		i++;
	}
}
