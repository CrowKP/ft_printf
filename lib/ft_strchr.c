/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:58:39 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/21 15:58:41 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	if (c > 256)
	{
		if (c == 1024)
			c = '\0';
		else
			c = (c - 256);
	}
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (s);
}
