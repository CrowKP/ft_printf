/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:02:22 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/23 15:02:23 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == 0 && s == 0)
		return (0);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
