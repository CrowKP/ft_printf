/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nosign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:49 by aigarcia          #+#    #+#             */
/*   Updated: 2022/09/15 14:36:50 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_putnosinbr(unsigned int n)
{
	int				it;
	unsigned int	uint_max;

	it = ft_numlen(n);
	uint_max = 4294967295;
	if (n < 0)
		if (ft_putnosinbr(uint_max - n) == -1)
			return (-1);
	if (n > 9)
		if (ft_putnosinbr(n / 10) == -1)
			return (-1);
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (it);
}

int	ft_printnosign(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
	{
		len = ft_putchar('0');
		if (len == -1)
			return (-1);
	}
	else
	{
		len = ft_putnosinbr(n);
		if (len == -1)
			return (-1);
	}
	return (len);
}
