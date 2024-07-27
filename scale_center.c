#include "fdf.h"

void    scale_center(t_coordinates **clean_map, t_map_size *map, float scale)
{
    float s_width;
    float s_height;
    int h;
    int w;

    h = 0;
    s_width = (map->max_x - map->min_x) * scale;
    s_height = (map->max_y - map->min_y) * scale;
    while (h < map->h)
    {
        w = 0;
        while (w < map->w)
        {
            clean_map[h][w].x = (clean_map[h][w].x - map->min_x)*scale + (WIDTH - s_width) / 2;
            clean_map[h][w].y = (clean_map[h][w].y - map->min_y)*scale + (HEIGHT - s_height) / 2;
            w++;
        }
        h++;
    }
}

void   get_scale(t_coordinates **clean_map, t_map_size *map)
{
    float range_x;
    float range_y;
    float scale;

    range_x = map->max_x - map->min_x + 1;
    range_y = map->max_y - map->min_y + 1;
    range_x = ((WIDTH) - 150) / (range_x);
    range_y = ((HEIGHT) - 100) / (range_y);
    scale = range_x < range_y ? range_x : range_y;
    scale_center(clean_map, map, scale);
}

void    ft_draw(t_coordinates **clean_map, t_map_size *map, mlx_image_t* image)
{
    int rows;
    int columns;

    rows = 0;
    get_scale(clean_map, map);
    clean_image(image);
    while(rows < map->h)
    {
        columns = 0;
        while (columns < map->w)
        {
            if (columns + 1 < map->w)
                bresenham_line(image, clean_map[rows][columns].x, clean_map[rows][columns].y, clean_map[rows][columns + 1].x, clean_map[rows][columns + 1].y, clean_map[rows][columns].color, clean_map[rows][columns + 1].color);
            if (rows + 1 < map->h)
                bresenham_line(image, clean_map[rows][columns].x, clean_map[rows][columns].y, clean_map[rows + 1][columns].x, clean_map[rows + 1][columns].y, clean_map[rows][columns].color, clean_map[rows + 1][columns].color);
            columns++;
        }
        rows++;
    }
}

////////////////////////////////////////
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
/////////////////////////////////////////

void    draw_three_D(t_coordinates **clean_map, t_map_size *map)
{
    mlx_t* mlx;
    mlx_image_t* image;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "fil de fer", false)))
	{
        ft_free_m(clean_map, map->h);
        exit(2);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
        ft_free_m(clean_map, map->h);
		mlx_close_window(mlx);
		exit(2);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
        ft_free_m(clean_map, map->h);
		mlx_close_window(mlx);
		exit(2);
	}
    ft_draw(clean_map, map, image);
    mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
	mlx_terminate(mlx);
}

void    clean_image(mlx_image_t *image)
{
    int i;
    int j;

    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            mlx_put_pixel(image, j, i, 0x000000ff);
            j++;
        }
        i++;
    }
}