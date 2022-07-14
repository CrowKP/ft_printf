/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:26:13 by aigarcia          #+#    #+#             */
/*   Updated: 2022/06/21 16:26:15 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(const char *str1, const char *str2, unsigned int n)
{
	unsigned char	ch1;
	unsigned char	ch2;

	while (n > 0)
	{
		ch1 = (unsigned char) *str1++;
		ch2 = (unsigned char) *str2++;
		if (ch1 != ch2)
			return (ch1 - ch2);
		if (ch1 == '\0')
			return (0);
		n--;
	}
	return (0);
}
