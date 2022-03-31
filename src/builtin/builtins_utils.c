/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:33:34 by arossign          #+#    #+#             */
/*   Updated: 2022/03/28 16:02:14 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_num_arg(char c, char *error_msg)
{
	if (ft_isdigit(c))
	{
		ft_putendl_fd(error_msg, STDERR_FILENO);
		return (g_vars.exit_code = 1, 1);
	}
	return (0);
}
