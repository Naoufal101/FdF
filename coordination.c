#include "fdf.h"

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
        ft_free(splited_line);
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
    if (!matrix[rows] || !splited_line)
        return (ft_free_m(matrix, rows));
    while (splited_line[columns] && columns < map->w)
    {
        matrix[rows][columns].z = ft_atoi(splited_line[columns]);
        matrix[rows][columns].color = get_color(ft_strrchr(splited_line[columns], ','));
        iso_project(columns, rows, matrix[rows][columns].z, matrix);
        if (matrix[rows][columns].x < map->min_x)
            map->min_x = matrix[rows][columns].x;
        if (matrix[rows][columns].y < map->min_y)
            map->min_y = matrix[rows][columns].y;
        if (matrix[rows][columns].x > map->max_x)
            map->max_x = matrix[rows][columns].x;
        if (matrix[rows][columns].y > map->max_y)
            map->max_y = matrix[rows][columns].y;
        columns++;
    }
    rows++;
    return (matrix);
}

t_coordinates   **get_matrix(int fd, t_map_size *map)
{
    t_coordinates **matrix;
    char    **splited_line;
    char    *line;

    matrix = malloc(map->h * sizeof(t_coordinates *));
    if (!matrix)
        return (NULL);
    line = gnl_matrix(matrix, fd);
    while (line)
    {
        splited_line = ft_split(line, ' ');
        matrix = fill_matrix(matrix, splited_line, map);
        if (!matrix)
            map_error(fd, NULL, splited_line, line);
        free(line);
        ft_free(splited_line);
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