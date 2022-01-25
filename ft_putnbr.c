/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:07:28 by juhagon           #+#    #+#             */
/*   Updated: 2021/11/22 13:20:19 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_putnbr(int i)
{
	int		rtn;
	long	x;

	x = i;
	rtn = 0;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x < 10)
		ft_putchar(x + '0');
	else if (x > 0)
	{
		rtn = ft_putnbr(x / 10);
		ft_putchar(x % 10 + '0');
	}
	rtn += 1;
	return (rtn);
}

int	count_digits(int i, int log)
{
	if (i == 0)
		return (log + 1);
	if (i < 0)
	{
		i = -i;
		log = log + 1;
	}
	while (i)
	{
		log++;
		i = i / 10;
	}
	return (log);
}

int	count_usdigits(unsigned int i, int log)
{
	if (i == 0)
		return (log + 1);
	if (i < 0)
	{
		i = -i;
		log = log + 1;
	}
	while (i)
	{
		log++;
		i = i / 10;
	}
	return (log);
}

int	count_exdigits(int i, int log)
{
	long int	nbr2;

	nbr2 = (long)i;
	if (nbr2 < 0)
	{
		log++;
	}
	if (nbr2 < 16)
		log++;
	else if (nbr2 >= 16)
	{
		return (count_exdigits(i / 16, ++log));
	}
	return (log);
}

void	ft_putusnbr(unsigned	int i)
{
	unsigned long	x;

	x = i;
	if (x < 10)
		ft_putchar(x + '0');
	else if (x > 0)
	{
		ft_putusnbr(x / 10);
		ft_putchar(x % 10 + '0');
	}
}
