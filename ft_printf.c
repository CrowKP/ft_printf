/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:57:30 by aigarcia          #+#    #+#             */
/*   Updated: 2022/08/18 15:57:32 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	done;

	done = 0;
	if (format == 'c')
		done += ft_putchar(va_arg(args, int));
	else if (format == 's')
		done += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		done += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		done += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		done += ft_printnosign(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		done += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		done += ft_putchar('%');
	return (done);
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
			done += ft_putchar(format[it]);
		it++;
	}
	va_end(arg);
	return (done);
}
