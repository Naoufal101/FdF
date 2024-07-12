/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:25:15 by nhimad            #+#    #+#             */
/*   Updated: 2023/12/26 15:33:31 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(long n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static char	*n_write(char *b, long n2, int l, int sign)
{
	int	i;

	i = 0;
	if (sign)
		b[i++] = '-';
	b[l--] = 0;
	while (l >= i)
	{
		b[l--] = (n2 % 10) + 48;
		n2 /= 10;
	}
	return (b);
}

char	*ft_itoa(int n)
{
	int		l;
	int		sign;
	long	n2;
	char	*b;

	sign = 0;
	l = 0;
	n2 = n;
	if (n2 < 0)
	{
		sign = 1;
		n2 *= -1;
		l++;
	}
	l += number_length(n2);
	b = ft_calloc(l + 1, sizeof(char));
	if (!b)
		return (0);
	return (n_write(b, n2, l, sign));
}
