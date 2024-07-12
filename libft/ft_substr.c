/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:54:38 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/26 15:33:31 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft2_strdup(const char *s1, size_t size)
{
	char	*str;

	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sl;

	if (!s)
		return (0);
	sl = 0;
	if (start > ft_strlen(s))
		return (ft2_strdup(s, 1));
	while (s[start + sl] && sl < len)
		sl++;
	return (ft2_strdup(s + start, sl + 1));
}
