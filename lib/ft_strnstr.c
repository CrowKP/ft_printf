/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:59:35 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/27 19:59:36 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t n)
{
	size_t	it;

	it = ft_strlen(nee);
	if (*nee == '\0')
		return ((char *)hay);
	while (*hay != '\0' && it <= n--)
	{
		if (!(ft_strncmp((char *)hay, (char *)nee, it)))
			return ((char *)hay);
		hay++;
	}
	return (0);
}
