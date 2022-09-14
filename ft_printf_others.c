#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

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
	char	*num;

	done = 0;
	num = ft_itoa(n);
	if (!num)
	{
		free(num);
		return (-1);
	}
	done = ft_printstr(num);
	free(num);
	return (done);
}
