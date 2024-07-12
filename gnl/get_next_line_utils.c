/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:43:55 by nhimad            #+#    #+#             */
/*   Updated: 2024/06/09 15:32:22 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstadd_back(t_blist **bl, char	*content)
{
	t_blist	*last;
	t_blist	*new;

	if (!content)
		return (0);
	new = malloc(sizeof(t_blist));
	if (!new)
	{
		ft_clean(bl);
		free(content);
		return (0);
	}
	new->buffer = content;
	new->next = 0;
	if (!bl[0])
	{
		bl[0] = new;
		return (1);
	}
	last = ft_last_node(bl[0]);
	last->next = new;
	return (1);
}

t_blist	*ft_last_node(t_blist *lst)
{
	t_blist	*ln;

	ln = lst;
	while (lst)
	{
		ln = lst;
		lst = lst->next;
	}
	return (ln);
}

void	ft_clean(t_blist **bl)
{
	t_blist	*node;
	t_blist	*l;

	l = *bl;
	node = l;
	while (node)
	{
		node = node->next;
		free (l->buffer);
		free (l);
		l = node;
	}
	*bl = 0;
}

void	ft_strlcats(char *dst, const char *src, size_t dstsize)
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
}

void	ft_set(t_blist **list)
{
	t_blist	*last;
	char	*s;
	int		i;
	char	*b;

	b = 0;
	i = 0;
	last = ft_last_node(*list);
	s = last->buffer;
	i = line_size(last);
	if (s[i])
	{
		b = malloc(BUFFER_SIZE + 1);
		if (!b)
		{
			ft_clean(list);
			return ;
		}
		b[0] = 0;
		ft_strlcats(b, (s + i), BUFFER_SIZE + 1);
	}
	ft_clean(list);
	ft_lstadd_back(list, b);
}
