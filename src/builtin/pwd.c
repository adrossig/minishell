/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:35 by arossign          #+#    #+#             */
/*   Updated: 2022/03/28 16:39:55 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(char **args)
{
	char	buff[PATH_MAX];
	int		i;

	i = 0;
	(void)args;
	if (getcwd(buff, sizeof(buff)) == NULL)
		return (g_vars.exit_code = 1, ft_putstr_fd("minishell: pwd: ", 2),
			ft_putstr_fd(args[0], STDERR_FILENO), perror(" \b"));
	else
		ft_putendl_fd(buff, STDOUT_FILENO);
}