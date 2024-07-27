#ifndef FDF_H
# define FDF_H

#include "fcntl.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>

#define WIDTH 1024
#define HEIGHT 768

#define ISO_ANGLE (M_PI / 6)

#define ISO_COS cos(ISO_ANGLE) // cos(30°)
#define ISO_SIN sin(ISO_ANGLE)  // sin(30°)


typedef struct s_coordinates
{
    float    x;
    float    y;
    float    z;
    unsigned int    color;
}            t_coordinates;
 
typedef struct s_map_size
{
    int w;
    int h;
    int min_x;
    int min_y;
    int max_x;
    int max_y;
}       t_map_size;

typedef struct s_draw
{
    int move_x;
    int move_y;
    int dx;
    int dy;
    int err;
    int temp;
}   t_draw;

typedef struct s_colors
{
    int r1;
    int g1;
    int b1;
    int r2;
    int g2;
    int b2;
    float r;
    float g;
    float b;
    int steps;
    float r_step;
    float g_step;
    float b_step;
}   t_colors;

//get the map coordinations from the file
t_coordinates   **get_coordinates(char *str, t_map_size *map);

//aka get_color
unsigned int get_color(char *str);

// isometric projaction function
void iso_project(int x, int y, int z, t_coordinates **c_map);

//scale the coordination and put the object in the middle of the window
void    scale_center(t_coordinates **clean_map, t_map_size *map, float scale);
void    draw_three_D(t_coordinates **clean_map, t_map_size *map);
void    ft_draw(t_coordinates **clean_map, t_map_size *map, mlx_image_t* image);
//bresenham algoritm
void bresenham_line(mlx_image_t* image, int x1, int y1, int x2, int y2, unsigned int color1, unsigned int color2);

void    clean_image(mlx_image_t *image);
int     columns_count(char **clean_map);

// error mangement
void    map_error(int fd, char *str, char **splited_line, char *line);
char *gnl_matrix(t_coordinates **matrix, int fd);
char *gnl(int fd);

//free memory
void	*ft_free_m(t_coordinates **str, int i);
void	*ft_free(char **st);
#endif