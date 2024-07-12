/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:10:13 by nhimad            #+#    #+#             */
/*   Updated: 2024/06/09 15:32:33 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct buffer
{
	char			*buffer;
	struct buffer	*next;
}	t_blist;

char	*get_next_line(int fd);
t_blist	*ft_last_node(t_blist *lst);
void	ft_strlcats(char *dst, const char *src, size_t dstsize);
void	ft_set(t_blist **list);
int		line_size(t_blist *lst);
int		ft_lstadd_back(t_blist **bl, char *content);
void	ft_clean(t_blist **bl);
int		newl_in(char *s);
char	*ft_line(t_blist **list);
#endif
