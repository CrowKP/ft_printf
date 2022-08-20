/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:57:04 by aigarcia          #+#    #+#             */
/*   Updated: 2022/08/18 15:57:05 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

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
