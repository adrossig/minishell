/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde_symbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:49:18 by ltorrean          #+#    #+#             */
/*   Updated: 2022/04/14 23:01:41 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_var_tilde(char *str, char **envp)
{
	int		last;
	char	*hol;
	char	*exp_name;
	char	*expanded;

	last = 0;
	hol = NULL;
	last = get_length_char_env(str);
	hol = ft_substr(str, 0, last);
	exp_name = ft_strdup((ft_getenv("HOME=", envp)));
	protect_expanded_name_quotes(&exp_name);
	free(hol);
	hol = NULL;
	if (last != (int)ft_strlen(str))
		hol = &str[last];
	expanded = ft_strjoin(exp_name, hol);
	return (free(exp_name), expanded);
}

char	*expand_tilde_symbol(char *line, char **envp)
{
	int		i;
	char	*hol;
	char	*env_var;

	i = -1;
	while (line && line[++i])
	{
		i += check_quotes(&line[i]);
		if (line && (!line[i - 1] || line[i - 1] == ' ')
			&& ((line[i] == '~' && line[i + 1] == ' ')
				|| (line[i] == '~' && !line[i + 1])
				|| (line[i] == '~' && line[i + 1] && line[i + 1] == '/')))
		{
			line[i--] = '\0';
			env_var = get_env_var_tilde(&line[i + 1], envp);
			hol = ft_strjoin(&line[0], env_var);
			free(env_var);
			free(line);
			line = hol;
		}
	}
	return (line);
}
