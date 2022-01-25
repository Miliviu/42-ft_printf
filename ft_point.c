/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:59:26 by juhagon           #+#    #+#             */
/*   Updated: 2021/11/22 14:46:51 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	rtn;

	rtn = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
	}
	if (nbr >= 16)
	{
		rtn += ft_putnbr_base(nbr / 16, base);
	}
	ft_putchar(base[nbr % 16]);
	rtn += 1;
	return (rtn);
}

static int	ft_putnbr_point(unsigned long int val, char *base)
{
	int	rtn;

	rtn = 0;
	if (val >= 16)
		rtn += ft_putnbr_point(val / 16, base);
	ft_putchar(base[val % 16]);
	rtn += 1;
	return (rtn);
}

unsigned long int	ft_putpoint(void *p)
{
	unsigned long long int	val;

	val = (unsigned long long int)p;
	ft_putstr("0x");
	return (ft_putnbr_point(val, "0123456789abcdef") + 2);
}
