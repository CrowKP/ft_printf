/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:24:32 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/30 18:24:34 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sizens;
	char	*newstr;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	sizens = ft_strlen(s1);
	while (sizens && ft_strchr(set, s1[sizens]))
		sizens--;
	newstr = ft_substr((char *)s1, 0, sizens +1);
	return (newstr);
}
