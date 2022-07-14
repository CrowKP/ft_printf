/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:59:27 by aigarcia          #+#    #+#             */
/*   Updated: 2022/07/01 17:59:31 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	it;

	it = 0;
	if (s != 0 && f != 0)
	{
		while (s[it] != '\0')
		{
			f(it, &s[it]);
			it++;
		}
	}
}
