/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:54 by arossign          #+#    #+#             */
/*   Updated: 2022/03/15 14:46:13 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include "libft.h"

void	ft_free_matrix(char ***m);
int		ft_matrixlen(char **m);
char	**ft_extend_matrix(char **in, char *newstr);
char	**ft_matrix_replace_in(char ***big, char **small, int n);
int		ft_matrix_putfd(char **m, int fd);
char	**ft_dup_matrix(char **m);

#endif
