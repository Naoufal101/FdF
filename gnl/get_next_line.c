/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:01:03 by nhimad            #+#    #+#             */
/*   Updated: 2024/06/09 15:32:28 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newl_in(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	line_size(t_blist *lst)
{
	int		i;
	int		length;
	char	*buffer;

	length = 0;
	while (lst)
	{
		i = 0;
		buffer = lst->buffer;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				return (++length);
			i++;
			length++;
		}
		lst = lst->next;
	}
	return (length);
}

void	fill_list(int fd, t_blist **lst)
{
	char	*buf;
	int		r;

	buf = 0;
	if (*lst)
		buf = (*lst)->buffer;
	while (!newl_in(buf))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
		{
			ft_clean(lst);
			return ;
		}
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
		{
			free (buf);
			return ;
		}
		buf[r] = 0;
		if (!ft_lstadd_back(lst, buf))
			return ;
	}
}

char	*ft_line(t_blist **list)
{
	t_blist	*lcount;
	int		count;
	char	*line;

	if (!(*list))
		return (0);
	count = line_size(*list);
	line = malloc(count + 1);
	if (!line)
	{
		ft_clean(list);
		return (0);
	}
	line[0] = 0;
	lcount = *list;
	while (lcount)
	{
		ft_strlcats(line, lcount->buffer, count + 1);
		lcount = lcount->next;
	}
	ft_set(list);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_blist	*blst;
	t_blist			*new;
	char			*buffer;

	buffer = 0;
	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
	{
		ft_clean(&blst);
		return (0);
	}
	new = 0;
	fill_list(fd, &blst);
	buffer = ft_line(&blst);
	return (buffer);
}
