/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:56:31 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/24 08:53:29 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	if (dst == src)
		return (dst);
	i = 0;
	s = src;
	d = dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
