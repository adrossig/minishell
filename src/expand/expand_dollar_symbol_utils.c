/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_symbol_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:45:48 by ltorrean          #+#    #+#             */
/*   Updated: 2022/04/19 15:32:09 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_double_quotes(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '"')
	{
		i++;
		while (line[i] && line[i] != '"')
			i++;
	}
	return (i);
}

char	*get_and_check_env_var(char *line, int i, char **envp, t_exit *exit_)
{
	char	*env_var;

	if (ft_isdigit(line[i + 2]))
		env_var = ft_strdup(&line[i + 3]);
	else if (line[i + 2] == '"' || line[i + 2] == '\'')
		env_var = ft_strdup(&line[i + 2]);
	else
		env_var = get_env_var(&line[i + 2], envp, exit_);
	return (env_var);
}

int	ft_check_if_heredoc(char *cmd, int end)
{
	int	i;

	i = end - 1;
	while (i > 1 && cmd[i] == ' ')
		i--;
	if (i >= 1 && cmd[i] == '<' && cmd[i - 1] == '<')
		return (1);
	return (0);
}
