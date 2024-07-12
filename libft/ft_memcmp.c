/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:18:06 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/13 19:47:33 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*so;
	unsigned char	*st;

	so = (unsigned char *)s1;
	st = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (so[i] == st[i] && i + 1 < n)
	{
		i++;
	}
	return (so[i] - st[i]);
}
