/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:22:32 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/21 12:45:29 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t l)
{
	size_t	i;
	char	*s;

	i = 0;
	s = str;
	while (i < l)
		s[i++] = (unsigned char)c;
	return (str);
}
