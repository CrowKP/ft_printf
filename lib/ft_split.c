/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:32:03 by aigarcia          #+#    #+#             */
/*   Updated: 2022/07/01 14:32:05 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	it;
	int	word;

	it = 0;
	word = 0;
	while (s[it])
	{
		if (s[it] != c)
		{
			word++;
			while (s[it] != c && s[it])
				it++;
		}
		else
			it++;
	}
	return (word);
}

static int	ft_size_words(char const *s, char c, int it)
{
	int	size;

	size = 0;
	while (s[it] != c && s[it])
	{
		size++;
		it++;
	}
	return (size);
}

static void	ft_free(char **strs, int jt)
{
	while (jt-- > 0)
		free(strs[jt]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		it;
	int		word;
	char	**strs;
	size_t	size;
	int		jt;

	it = 0;
	jt = -1;
	word = ft_count_word(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	while (++jt < word)
	{
		while (s[it] == c)
			it++;
		size = ft_size_words(s, c, it);
		strs[jt] = ft_substr(s, it, size);
		if (!strs[jt])
		{
			ft_free(strs, jt);
			return (0);
		}
		it += size;
	}
	strs[jt] = 0;
	return (strs);
}
