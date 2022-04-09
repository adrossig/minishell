/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorrean <ltorrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:33:34 by arossign          #+#    #+#             */
/*   Updated: 2022/04/08 12:04:11 by ltorrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_num_arg(char c, char *error_msg, t_exit *exit_)
{
	if (ft_isdigit(c))
	{
		ft_putendl_fd(error_msg, STDERR_FILENO);
		return (exit_->exit_code = 1, 1);
	}
	return (0);
}
