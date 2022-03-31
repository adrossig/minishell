/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:06:43 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 17:42:17 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include "libft.h"

int				ft_isascii(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isblank(int c);
int				ft_isalpha(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalnum(int c);
int				ft_charset(char str, char *charset);

#endif
