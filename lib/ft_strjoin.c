/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:27:52 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/29 15:27:54 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				it;
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == 0)
			return (0);
		it = -1;
		while (s1[++it])
			str[it] = s1[it];
		it = -1;
		while (s2[++it])
		{
			str[len1] = s2[it];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (0);
}
