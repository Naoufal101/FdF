/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:18 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/26 15:33:31 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in(char a, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (0);
	start = 0;
	last = ft_strlen(s1);
	if (last > 0)
		last--;
	while (s1[start] && in(s1[start], set))
		start++;
	while (last > start && in(s1[last], set))
		last--;
	return (ft_substr(s1, start, last - start + 1));
}
