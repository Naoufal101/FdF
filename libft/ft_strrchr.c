/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:15:44 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/26 17:00:30 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	l;

	l = ft_strlen(str);
	while (l >= 0)
	{
		if (str[l] == (char)c)
			return ((char *)&str[l]);
		l--;
	}
	return (0);
}
