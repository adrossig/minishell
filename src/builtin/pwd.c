/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:35 by arossign          #+#    #+#             */
/*   Updated: 2022/04/14 19:45:54 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(char **args, t_exit *exit_)
{
	char	buff[PATH_MAX];

	(void)args;
	if (getcwd(buff, sizeof(buff)) == NULL)
		return (exit_->exit_code = 1, ft_putstr_fd("minishell: pwd: ", 2),
			ft_putstr_fd(args[0], STDERR_FILENO), perror(" \b"));
	else
		ft_putendl_fd(buff, STDOUT_FILENO);
}
