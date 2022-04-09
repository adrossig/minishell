/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:46 by arossign          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:37 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_logic(char *cmds, char **envp, t_exit *exit_)
{
	char	*l_cmd;
	int		logic_opp;

	if (check_priorities(cmds))
		return (parse_logic(cmds, envp, exit_));
	logic_opp = 0;
	l_cmd = get_last_cmd(cmds, &logic_opp);
	if (!l_cmd)
		parse_input(cmds, envp, exit_);
	else
		parse_logic(cmds, envp, exit_);
	if (logic_opp == 1 && exit_->exit_code)
	{
		if (check_priorities(l_cmd))
			return (parse_logic(l_cmd, envp, exit_));
		parse_input(l_cmd, envp, exit_);
	}
	else if (logic_opp == -1 && !exit_->exit_code)
	{
		if (check_priorities(l_cmd))
			return (parse_logic(l_cmd, envp, exit_));
		parse_input(l_cmd, envp, exit_);
	}
}
