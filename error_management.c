#include "fdf.h"

void	*ft_free_m(t_coordinates **str, int i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
	return (0);
}

void	*ft_free(char **st)
{
    int i;
    char **str;

    i = 0;
    str = st;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

void    map_error(int fd, char *str, char **splited_line, char *line)
{
    free(line);
    ft_putendl_fd(str, 2);
    ft_free(splited_line);
    close (fd);
    exit (1);
}

char *gnl(int fd)
{
    char *line;

    line = get_next_line(fd);
    if(!line)
    {
        ft_putendl_fd("error in gnl or empthy file", 2);
        close (fd);
        exit (1);
    }
    return (line);
}

char *gnl_matrix(t_coordinates **matrix, int fd)
{
    char *line;

    line = get_next_line(fd);
    if(!line)
    {
        ft_putendl_fd("error in get_next_line gnl_matrix", 2);
        close (fd);
        free(matrix);
        exit (1);
    }
    return (line);
}
