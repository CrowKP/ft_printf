/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:39:43 by aigarcia          #+#    #+#             */
/*   Updated: 2022/09/15 14:39:44 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*swap(char *str, long int n, int it)
{
	while (n > 0)
	{
		str[it] = 48 + (n % 10);
		n = n / 10;
		it--;
	}
	return (str);
}

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

char	*ft_itoa(int n)
{
	int				it;
	char			*str;
	long int		nn;

	nn = n;
	it = 0;
	it = len(nn);
	str = (char *)malloc(sizeof(char) * (it + 1));
	if (!str)
	{
		return (0);
	}
	str[it--] = '\0';
	if (nn == 0)
		str[0] = 48;
	if (nn < 0)
	{
		str[0] = '-';
		nn = nn * -1;
	}
	str = swap(str, nn, it);
	return (str);
}
