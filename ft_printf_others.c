/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:39:11 by aigarcia          #+#    #+#             */
/*   Updated: 2022/09/15 14:39:12 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int	len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	it;

	it = len(n);
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar('-') == -1)
				return (-1);
			n *= -1;
		}
		if (n > 9)
			if (ft_putnbr(n / 10) == -1)
				return (-1);
		if (ft_putchar((n % 10) + '0') == -1)
			return (-1);
	}
	return (it);
}

int	ft_putstr(char *str)
{
	int	it;

	it = 0;
	while (str[it])
	{
		if (ft_putchar(str[it]) == -1)
			return (-1);
		it++;
	}
	return (ft_strlen(str));
}

int	ft_printstr(char *str)
{
	int	it;

	it = 0;
	if (str == 0)
	{
		return (ft_putstr("(null)"));
	}
	while (str[it])
	{
		if (ft_putchar(str[it]) == -1)
			return (-1);
		it++;
	}
	return (it);
}

int	ft_printnbr(int n)
{
	int		done;

	done = 0;
	done = ft_putnbr(n);
	return (done);
}
