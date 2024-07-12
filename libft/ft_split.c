/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:21:36 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/26 15:33:31 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char s)
{
	int	i;
	int	c;
	int	f;

	i = 0;
	c = 0;
	f = 1;
	while (str[i])
	{
		if (f && str[i] != s)
		{
			c++;
			f = 0;
		}
		else if (str[i] == s)
			f = 1;
		i++;
	}
	return (c);
}

static int	word_length(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static void	*ft_free(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;

	str = 0;
	if (!s)
		return (str);
	str = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[j] = ft_substr(s, 0, word_length(s, c));
			if (!str[j])
				return (ft_free(str, j));
			s += word_length(s, c);
			j++;
		}
		else
			s++;
	}
	str[j] = 0;
	return (str);
}
