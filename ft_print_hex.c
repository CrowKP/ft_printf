/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:35:24 by aigarcia          #+#    #+#             */
/*   Updated: 2022/09/15 14:35:25 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_hexformat(unsigned int num, const char format)
{
	int	check;

	check = 1;
	if (format == 'x')
		check = ft_putchar(num - 10 + 'a');
	if (format == 'X')
		check = ft_putchar(num - 10 + 'A');
	return (check);
}

int	ft_put_hex(unsigned int num, const char format)
{
	int	it;
	int	check;

	it = ft_hexlen(num);
	if (num >= 16)
	{
		if (ft_put_hex(num / 16, format) == -1)
			return (-1);
		if (ft_put_hex(num % 16, format) == -1)
			return (-1);
	}
	else
	{
		if (num <= 9)
			check = ft_putchar(num + '0');
		else
			check = ft_hexformat(num, format);
		if (check == -1)
			return (-1);
	}
	return (it);
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	done;

	done = 0;
	if (num == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		done++;
	}
	else
	{
		done = ft_put_hex(num, format);
		if (done == -1)
			return (-1);
	}
	return (done);
}
