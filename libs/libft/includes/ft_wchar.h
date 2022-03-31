/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:26:24 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/02 19:31:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include "libft.h"

void	ft_putwchar(wchar_t c);
void	ft_putwchar_fd(wchar_t c, int fd);
void	ft_putwstr_fd(wchar_t *str, int fd);
void	ft_putnwstr_fd(wint_t *wstr, int n, int fd);
size_t	ft_wstrlenz(wint_t *wstr);
int		ft_wchar_len(wint_t wch);

#endif
