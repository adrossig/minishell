/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:52:48 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 18:07:23 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include "libft.h"

int			ft_bintodec(int binary);
int			ft_atoi(const char *str);
int			ft_bintohexa(int binary);
int			ft_bintooctal(int binary);
int			ft_dectooctal(int decimal);
int			ft_todec(char *str, int base);
int			ft_atoi_base(const char *str, int base);
char		*ft_itoa(int n);
char		*ft_atouni(wchar_t w);
char		*ft_lltoa(long long n);
char		*ft_dectohexa(int decimal);
char		*ft_uitoa(unsigned int n);
char		*ft_itoa_uimax(uintmax_t nb);
char		*ft_ulltoa(unsigned long long n);
char		*ft_lltoa_base(long long nb, const char *base);
char		*ft_itoa_base(unsigned int n, const char *base);
char		*ft_ftoa(long double f, int precision, int dot);
char		*ft_fromdec(int number, int base, char *result);
char		*ft_utl_base(unsigned long long number, int base);
char		*ft_tohexa(char *base, unsigned long nbr, unsigned long lenght);
long long	ft_octaltobin(int octal);
long long	ft_octaltodec(int octal);
long long	ft_dectobin(int decimal);
long long	ft_hexatooctal(char *hex);
long long	ft_atoill(const char *nptr);
long long	ft_dectobin_recursive(int decimal);
int			value_len(uintmax_t nb, int base);
#endif
