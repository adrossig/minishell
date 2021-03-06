/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:53 by arossign          #+#    #+#             */
/*   Updated: 2022/04/16 20:16:32 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quotes(char *line)
{
	int	i;

	i = 0;
	if (line && line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
	}
	else if (line && line[i] == '"')
	{
		i++;
		while (line[i] && line[i] != '"')
			i++;
	}
	return (i);
}

int	check_single_quotes(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
	}
	return (i);
}

int	pipe_parse(char *line, t_list **cmds)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		i += check_quotes(&line[i]);
		if (!line[i++])
			return (-1);
		if (line[i] == '|')
		{
			line[i] = '\0';
			ft_lstadd_back(cmds, ft_lstnew(&line[++i]));
		}
	}
	return (0);
}

char	*expand_cmd(char *line, char **envp, t_exit *exit_)
{
	line = expand_dollar_symbol(ft_strdup(line), envp, exit_);
	line = expand_tilde_symbol(line, envp);
	line = get_wildcards_expressions(line);
	return (line);
}

void	parse_input(char *line, char **envp, t_exit *exit_)
{
	t_list	*cmds;

	line = expand_cmd(line, envp, exit_);
	if (!line)
		return ;
	cmds = ft_lstnew(line);
	pipe_parse(line, &cmds);
	exit_->exit_pipe = 1;
	fork_processes(cmds, envp, exit_);
	free(line);
	check_empty_line();
}
