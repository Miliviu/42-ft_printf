/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:12:35 by juhagon           #+#    #+#             */
/*   Updated: 2021/11/22 13:08:50 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char	*c)
{
	int	i;

	i = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[i])
		write(1, &c[i++], 1);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_arg(int i, const char *s, va_list args, int log)
{
	int	tmp;

	tmp = 0;
	if (s[i + 1] == 'd' || s[i + 1] == 'i')
	{
		tmp = va_arg(args, int);
		ft_putnbr(tmp);
		log = count_digits(tmp, log);
	}
	else if (s[i + 1] == 'c')
		ft_putchar(va_arg(args, int)), log++;
	else if (s[i + 1] == 's')
		log += ft_putstr(va_arg(args, char *));
	else if (s[i + 1] == 'u')
	{
		tmp = va_arg(args, unsigned int);
		ft_putusnbr(tmp);
		log = count_usdigits(tmp, log);
	}
	else
		log = check_auxargs(i, s, args, log);
	return (log);
}

int	check_auxargs(int i, const char *s, va_list args, int log)
{
	int	tmp;

	tmp = 0;
	if (s[i + 1] == 'x')
		log += ft_putnbr_base(va_arg(args, long int), "0123456789abcdef");
	else if (s[i + 1] == 'X')
		log += ft_putnbr_base(va_arg(args, long int), "0123456789ABCDEF");
	else if (s[i + 1] == 'p')
		log += ft_putpoint(va_arg(args, long unsigned int *));
	else if (s[i + 1] == '%')
		ft_putchar('%'), log++;
	return (log);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		log;

	i = 0;
	log = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			log = check_arg(i, s, args, log);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			log++;
		}
		i++;
	}
	va_end(args);
	return (log);
}
