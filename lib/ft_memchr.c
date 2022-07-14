/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:28 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/21 16:48:29 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memchr(const void *str, int c, unsigned int n)
{
	unsigned char	*src;
	unsigned char	ch;

	src = (unsigned char *)str;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*src == ch)
			return (src);
		src++;
		n--;
	}
	return (0);
}
