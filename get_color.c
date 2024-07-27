#include "fdf.h"

void iso_project(int x, int y, int z, t_coordinates **c_map)
{

    c_map[y][x].x = (x - y) * ISO_COS;
    c_map[y][x].y = ((x + y) * ISO_SIN - z);
}

int get_Hex_value(char h, char *base)
{
    int i;

    i = 0;
    while(base[i])
    {
        if (base[i] == h)
            break;
        i++;
    }
    return (i);
}

unsigned int get_color(char *str)
{
    unsigned int color;
    char *base;
    int i;

    i = 3;
    color = 0;
    base = "0123456789abcdef";
    if (!str)
        return (0xffffffff); //test to approve.
    if (str[1] == '0' && (str[2] == 'x' || str[2] == 'X'))
    {
        while (str[i] && ft_strchr(base, ft_tolower(str[i])) && i < 12)
        {
            color = color * 16 + get_Hex_value(ft_tolower(str[i]), base);
            i++;
        }
    }
    color = color << 8;
    color += 255;
    return (color);
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