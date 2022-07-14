#include "ft_printf.h"
#include <stdarg.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	it;

	it = 0;
	while (str[it])
	{
		write(1, &str[it], 1);
		it++;
	}
}

int	ft_printstr(char *str)
{
	int it;

	it = 0;
	if (str == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[it])
	{
		write(1, &str[it], 1);
		it++;
	}
	return (it);
}

int	ft_formats(va_list args, const char format)
{
	int	done;

	done = 0;
	if (format == 'c')
		done += ft_putchar(va_arg(args, int));
	else if (format == 's')
		done += ft_printstr(va_arg(args, char*));
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

int main()
{
	ft_printf("%s", "Hello World");
	ft_printf("%c", '\n');
}