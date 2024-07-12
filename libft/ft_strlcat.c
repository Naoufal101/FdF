/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:01:27 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/12 12:18:23 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	i;

	ds = 0;
	while (dst[ds] && ds < dstsize)
		ds++;
	i = 0;
	while (src[i] && (ds + i + 1) < dstsize)
	{
		dst[ds + i] = src[i];
		i++;
	}
	if (ds + i < dstsize)
		dst[ds + i] = 0;
	return (ds + ft_strlen(src));
}
