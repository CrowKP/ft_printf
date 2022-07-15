#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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
	int	it;

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

int	ft_ptrlen(unsigned long long it)
{
	int	len;

	len = 0;
	while (it != 0)
	{
		it++;
		it = it / 16;
	}
	return (len);
}

void	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	done;

	done = 0;
	done += write(1, "0x", 2);
	if (ptr == 0)
		done += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		done += ft_ptrlen(ptr);
	}
	return (done);
}

int	ft_printnbr(int n)
{
	int		done;
	char	*num;

	done = 0;
	num = ft_itoa(n);
	done = ft_printstr(num);
	free(num);
	return (done);
}

int	ft_printnosign(unsigned int n)
{
	int		done;
	char*	num;
}

int	ft_formats(va_list args, const char format)
{
	int	done;

	done = 0;
	if (format == 'c')
		done += ft_putchar(va_arg(args, int));
	else if (format == 's')
		done += ft_printstr(va_arg(args, char*));
	else if (format == 'p')
		done += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		done += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		done += ft_printnosign(va_arg(args, unsigned int));
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
	int	b;

	b = 41465;
	printf("%d\n", b);
	ft_printf("%d\n", b);
}