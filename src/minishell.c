/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:47 by arossign          #+#    #+#             */
/*   Updated: 2022/04/20 10:57:40 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_atoi_mod(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
		neg = -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str)
		return (0);
	return (res * neg);
}

void	update_shlvl(char **envp, t_exit *exit_)
{
	int		i;
	int		shlvl;
	char	*hol;
	char	*shlvl_str;
	char	**args;

	i = 0;
	while (envp && envp[i])
	{
		envp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (ft_getenv("SHLVL=", envp))
		shlvl = ft_atoi_mod(ft_getenv("SHLVL=", envp));
	else
		shlvl = 0;
	hol = ft_itoa(shlvl + 1);
	shlvl_str = ft_strjoin("SHLVL=", hol);
	args = ft_split(shlvl_str, ' ');
	free (hol);
	ft_export(args, envp, exit_);
	free(shlvl_str);
	free_2d(args);
}

char	*utils(char *prompt, char **envp, t_exit *exit_)
{
	char	*line;
	char	buff[PATH_MAX];
	char	s[PATH_MAX];

	s[0] = 0;
	if (exit_->exit_code > 0)
		ft_strcpy(s, RED ARW RES);
	else
		ft_strcpy(s, GREEN ARW RES);
	if (ft_getenv("HOME=", envp) && ft_getenv("PWD=", envp)
		&& !ft_strcmp(ft_getenv("PWD=", envp), ft_getenv("HOME=", envp)))
		ft_strcat(s, PURPLE MINISHELL_HOME);
	else
	{
		ft_strcat(s, RED_LIGHT);
		if (getcwd(buff, sizeof(buff)) == NULL)
			ft_strcat(s, prompt);
		else
			ft_strcat(s, ft_strrchr(buff, '/') + 1);
	}
	ft_strcat(s, " "RES);
	line = readline_config(s);
	return (line);
}

void	write_start_minishell(void)
{
	ft_putstr_fd(RED"\n"
		" ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    "
		"\n"
		"▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    "
		"\n"
		"▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    "
		"\n"
		"▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    "
		"\n"
		"▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒"
		"\n"
		"░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░"
		"\n"
		"░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░"
		"\n"
		"░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   "
		"\n"
		"       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░"
		"\n"
		RES, 2);
}

int	main(int ac, char **av, char **envp)
{
	t_exit	exit_;

	write_start_minishell();
	exit_.exit_shell = 257;
	exit_.exit_code = 0;
	exit_.exit_pipe = 0;
	update_shlvl(envp, &exit_);
	display_prompt(MINISHELL, envp, &exit_);
	(void)ac;
	(void)av;
	return (0);
}
