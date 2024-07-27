#include "fdf.h"

void check_name(char *str)
{
    int l;

    l = ft_strlen(str);
    if (l - 4 <= 0 || ft_strncmp((str + l - 4), ".fdf", 4))
    {
        ft_putendl_fd("File format must be *.fdf", 2);
        exit (1);
    }
}

void map_init(t_map_size *map_info)
{
    map_info->h = 0;
    map_info->w = 0;
    map_info->max_x = 0;
    map_info->min_x = 0;
    map_info->max_y = 0;
    map_info->min_y = 0;
}

int main(int argc, char **argv)
{
    t_map_size      map_info;
    t_coordinates   **clean_map;

    map_init(&map_info);
    if (argc != 2)
    {
       ft_putendl_fd("Usage : ./fdf <filename>", 2);
        return (1); 
    }
    check_name(argv[1]);
    clean_map = get_coordinates(argv[1], &map_info);
    if (!clean_map)
    {
        ft_putendl_fd("error  in get_coordinate", 2);
        return (0);
    }
    draw_three_D(clean_map, &map_info);
    ft_free_m(clean_map, map_info.h);
}