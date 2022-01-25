/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:37:36 by juhagon           #+#    #+#             */
/*   Updated: 2021/11/22 14:47:42 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int					ft_printf(const char *s, ...);
int					ft_putnbr(int i);
int					count_digits(int i, int log);
int					ft_putstr(char *c);
void				ft_putchar(char c);
void				ft_putusnbr(unsigned	int i);
int					ft_putnbr_base(unsigned int nbr, char *base);
unsigned long int	ft_putpoint(void *p);
int					count_exdigits(int i, int log);
int					count_usdigits(unsigned int i, int log);
int					check_arg(int i, const char *s, va_list args, int log);
int					check_auxargs(int i, const char *s, va_list args, int log);

#endif
