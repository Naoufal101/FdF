/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:27:35 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/24 09:02:57 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		l;
	char		*d;
	const char	*s;

	d = dst;
	s = src; 
	if (dst == src)
		return (dst);
	if (s < d)
	{
		l = len;
		while (l-- > 0)
			d[l] = s[l];
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
