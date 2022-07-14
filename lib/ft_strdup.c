/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:34:36 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/29 14:34:44 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*dest;
	unsigned int	len;
	unsigned int	it;

	it = 0;
	len = ft_strlen(str);
	dest = malloc(sizeof(*str) * (len + 1));
	if (dest == 0)
		return (0);
	while (str[it])
	{
		dest[it] = str[it];
		it++;
	}
	dest[it] = '\0';
	return (dest);
}
