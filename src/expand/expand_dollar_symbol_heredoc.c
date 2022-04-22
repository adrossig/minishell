/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_symbol_heredoc.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:42:48 by ltorrean          #+#    #+#             */
/*   Updated: 2022/04/19 15:30:55 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	valid_symbol_heredoc(char c)
{
	if (!c || c == '%' || c == '^' || c == '#' || c == '+' || c == '/'
		|| c == '-' || c == '~' || c == '=' || c == ':' || c == ' '
		|| c == '"' || c == '\'')
		return (1);
	return (0);
}

static char	*get_env_var_heredoc(char *str, char **envp, t_exit *exit_)
{
	int		last;
	char	*hol;
	char	*name;
	char	*exp_name;
	char	*expanded;

	last = 0;
	hol = NULL;
	name = NULL;
	if (str[0] == '?' && ++last)
		exp_name = ft_itoa(exit_->exit_code);
	else
	{
		last = get_length_char_env(str);
		hol = ft_substr(str, 0, last);
		name = ft_strjoin(hol, "=");
		exp_name = ft_strdup((ft_getenv(name, envp)));
		free(hol);
		hol = NULL;
	}
	if (last != (int)ft_strlen(str))
		hol = &str[last];
	expanded = ft_strjoin(exp_name, hol);
	return (free(name), free(exp_name), expanded);
}

char	*expand_dollar_s_heredoc(char *line, char **envp, t_exit *exit_)
{
	int		i;
	char	*hol;
	char	*env_var;

	i = -1;
	while (line && line[++i])
	{
		if (line && line[i] == '$' && !valid_symbol_heredoc(line[i + 1]))
		{
			line[i--] = '\0';
			if (ft_isdigit(line[i + 2]))
				env_var = ft_strdup(&line[i + 3]);
			else
				env_var = get_env_var_heredoc(&line[i + 2], envp, exit_);
			hol = ft_strjoin(&line[0], env_var);
			free(env_var);
			free(line);
			line = hol;
		}
	}
	return (line);
}
