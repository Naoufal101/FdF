#include "fdf.h"

void drawing_loop(mlx_image_t* image, int x1, int y1, int x2, int y2, t_draw mat, t_colors colors)
{
    unsigned int current_color;

    while (1)
    {
        current_color = ((int)colors.r << 24) | ((int)colors.g << 16) | (int)colors.b << 8 | 255;
        mlx_put_pixel(image, x1, y1, current_color);
        if (x1 == x2 && y1 == y2) break;
        mat.temp = mat.err;
        if (mat.temp > -mat.dx) {
            mat.err -= mat.dy;
            x1 += mat.move_x;
        }
        if (mat.temp < mat.dy) {
            mat.err += mat.dx;
            y1 += mat.move_y;
        }
        colors.r += colors.r_step;
        colors.g += colors.g_step;
        colors.b += colors.b_step;
    }
}

void bresenham_line(mlx_image_t* image, int x1, int y1, int x2, int y2, unsigned int color1, unsigned int color2)
{
    t_draw mat;
    t_colors colors;

    mat.dx = abs(x2 - x1);
    mat.dy = abs(y2 - y1);
    mat.move_x = (x1 < x2) ? 1 : -1;
    mat.move_y = (y1 < y2) ? 1 : -1;
    mat.err = (mat.dx > mat.dy ? mat.dx : -mat.dy) / 2;
    colors.steps = (mat.dx > mat.dy) ? mat.dx : mat.dy;
    colors.r1  = (color1 >> 24) & 0xFF;
    colors.g1 = (color1 >> 16) & 0xFF;
    colors.b1 = (color1 >> 8) & 0xFF;
    colors.r2 = (color2 >> 24) & 0xFF;
    colors.g2 = (color2 >> 16) & 0xFF;
    colors.b2 = (color2 >> 8) & 0xFF;
    colors.r_step = (float)(colors.r2 - colors.r1) / colors.steps;
    colors.g_step = (float)(colors.g2 - colors.g1) / colors.steps;
    colors.b_step = (float)(colors.b2 - colors.b1) / colors.steps;
    colors.r = colors.r1;
    colors.g = colors.g1;
    colors.b = colors.b1;
    drawing_loop(image, x1, y1, x2, y2, mat, colors);
}