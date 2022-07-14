/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:21:24 by aigarcia          #+#    #+#             */
/*   Updated: 2022/07/01 18:21:26 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	it;

	it = 0;
	if (s)
	{
		while (s[it])
			write(fd, &s[it++], 1);
		write(fd, "\n", 1);
	}
}
