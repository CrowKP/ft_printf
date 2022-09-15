/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:38:50 by aigarcia          #+#    #+#             */
/*   Updated: 2022/09/15 14:38:51 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	done;

	done = 0;
	if (format == 'c')
		done = ft_check(done, va_arg(args, int));
	else if (format == 's')
		done = ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		done += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		done = ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		done += ft_printnosign(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		done += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		done = ft_check(done, '%');
	if (done == -1)
		return (-1);
	return (done);
}

int	ft_check(int done, int format)
{
	int	check;

	check = ft_putchar(format);
	if (check == -1)
		return (-1);
	else
	{
		done += check;
		return (done);
	}
}

int	ft_printf(const char *format, ...)
{
	int		it;
	va_list	arg;
	int		done;

	it = 0;
	done = 0;
	va_start (arg, format);
	while (format[it])
	{
		if (format[it] == '%')
		{
			done += ft_formats(arg, format[it + 1]);
			it++;
		}
		else
			done = ft_check(done, format[it]);
		if (done == -1)
			return (-1);
		it++;
	}
	va_end(arg);
	return (done);
}
