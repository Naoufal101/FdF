#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"


typedef struct s_coordinates
{
    float    x;
    float    y;
    float    z;
    float    color;
}            t_coordinates;
 
typedef struct s_map_size
{
    int w;
    int h;
}       t_map_size;

static void	*ft_free(void **st)
{
    int i;
    char **str;

    i = 0;
    str = (char **) st;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int columns_count(char **clean_map)
{
    int i;

    i = 0;
    while (clean_map[i])
        i++;
    if (clean_map[i-1][0] == '\n')
        i--;
    return (i);
}

/*
int main (int argc, char *argv[])
{
    int     i = 0;
    int     fd;
    int     columns;
    int     rows;
    char    *map;
    char    **clean_map;

    rows = 0;
    
    map = get_next_line(fd);
    if(!map)
    {
        ft_putendl_fd("error in gnl or empthy file", 2);
        return (1);
    }
    while (map)
    {
        clean_map = ft_split(map, ' ');
        if (!clean_map)
        {
            free(map);
            ft_free(clean_map);
            return (1);
        }
        if (i == 0)
        {
            columns = columns_count(clean_map);
            if (columns == 0)
            {
                ft_putendl_fd("No data found.", 2);
                free(map);
                ft_free(clean_map);
                return (1);
            }
        }
        i = 0;
        while (clean_map[i])
        {
            ft_putstr_fd(clean_map[i++], 1);
        }
        printf("i: %d, colums:%d\n", i, columns);
        if (i < columns)
        {
            ft_putendl_fd("Found wrong line length. Exiting.", 2);
            ft_free(clean_map);
            return (1);
        }
        free(map);
        map = get_next_line(fd);
        free(clean_map);
        rows++;
    }
    close(fd);
    printf("rows: %d\n", rows);

    t_coordinates **coor = malloc(rows * sizeof(t_coordinates *));

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        ft_putendl_fd("error in open or there is no such a file", 2);
        ft_free(coor);
        return (1);
    }

    map = get_next_line(fd);
    if(!map)
    {
        ft_putendl_fd("error in gnl or empthy file", 2);
        ft_free(coor);
        return (1);
    }
    rows = 0;
    while (map)
    {
        clean_map = ft_split(map, ' ');
        if (!clean_map)
        {
            free(map);
            ft_free(clean_map);
            return (1);
        }
       
        i = 0;
        coor[rows] = malloc(columns * sizeof(t_coordinates));
        while (clean_map[i] && i < columns)
        {
            coor[rows][i].x = i;
            coor[rows][i].y = rows;
            coor[rows][i].z = ft_atoi(clean_map[i]);
            ft_putstr_fd(clean_map[i++], 1);
        }
        printf("i: %d, colums:%d\n", i, columns);
        if (i < columns)
        {
            ft_putendl_fd("Found wrong line length. Exiting.", 2);
            ft_free(clean_map);
            return (1);
        }
        free(map);
        map = get_next_line(fd);
        free(clean_map);
        rows++;
    }
}
*/

int ft_open(char *str)
{
    int fd;

    fd = open(str, O_RDONLY);
    if(fd == -1)
    {
        ft_putendl_fd("error in open or there is no such a file", 2);
        exit(1);
    }
    return (fd);
}

void    map_error(int fd, char *str, char **splited_line, char *line)
{
    ft_putendl_fd(str, 2);
    free(line);
    ft_free((void **)splited_line);
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

void    map_size(t_map_size *map, int fd)
{
    char    *line;
    char    **splited_line;
    int     columns;

    line = gnl(fd);
    while (line)
    {
        splited_line = ft_split(line, ' ');
        if (!splited_line)
            map_error(fd, NULL, splited_line, line);
        if (map->h == 0)
        {
            map->w = columns_count(splited_line);
            if (map->w == 0)
                map_error(fd, "No data found.", splited_line, line);
        }
        columns = columns_count(splited_line);
        if (columns < map->w)
            map_error(fd, "Found wrong line length. Exiting.", splited_line, line);
        free(line);
        free(splited_line);
        line = get_next_line(fd);
        map->h++;
    }
    close(fd);
}

t_coordinates  **fill_matrix(t_coordinates **matrix, char **splited_line, t_map_size *map)
{
    static int rows;
    int columns;

    columns = 0;
    matrix[rows] = malloc(map->w * sizeof(t_coordinates));
    if (!matrix[rows])
        return (NULL);
    while (splited_line[columns] && columns < map->w)
    {
        matrix[rows][columns].x = columns;
        matrix[rows][columns].y = rows;
        matrix[rows][columns].z = ft_atoi(splited_line[columns]);
        columns++;
    }
    rows++;
    return (matrix);
}
void    get_matrix_error(t_coordinates **matrix, int fd, char **splited_line, char *line)
{
    free(matrix);
    map_error(fd, NULL, splited_line, line);
}

t_coordinates   **get_matrix(int fd, t_map_size *map)
{
    t_coordinates **matrix;
    char    **splited_line;
    char    *line;
    
    matrix = malloc(map->h * sizeof(t_coordinates *));
    if (!matrix)
        return (NULL);
    line = gnl(fd); //need to free matrix.
    while (line)
    {
        splited_line = ft_split(line, ' ');
        if (!splited_line)
            get_matrix_error(matrix, fd, splited_line, line);
        matrix = fill_matrix(matrix, splited_line, map);
        if (!matrix)
            get_matrix_error(matrix, fd, splited_line, line);
        free(line);
        free(splited_line);
        line = get_next_line(fd);
    }
    return (matrix);
}

t_coordinates   **get_coordinates(char *str, t_map_size *map)
{
    int fd;

    fd = ft_open(str);
    map_size(map, fd);
    fd = ft_open(str);
    return (get_matrix(fd, map));
}

void    print_coordinates(t_coordinates **clean_map, t_map_size *map)
{
    int rows;
    int columns;

    rows = 0;
    printf ("rows: %d,,, width: %d\n", map->h, map->w);
    while (rows < map->h)
    {
        columns = 0;
        while (columns < map->w)
        {
            printf("%f ", clean_map[rows][columns].z);
            columns++;
        }
        printf("\n");
        rows++;
    }
}

int main(int argc, char **argv)
{
    t_map_size      map;
    t_coordinates   **clean_map;

    map.h = 0;
    map.w = 0;
    if (argc != 2)
    {
       ft_putendl_fd("Usage : ./fdf <filename>", 2);
        return (1); 
    }
    clean_map = get_coordinates(argv[1], &map);
    print_coordinates(clean_map, &map);
}