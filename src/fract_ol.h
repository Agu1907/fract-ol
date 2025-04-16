#ifndef FRACT_OL_H
#define FRACT_OL_H

#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

#define WIDTH 400
#define HEIGHT 400
#define MAX_ITER 200
#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364
#define ZOOM_IN 4
#define ZOOM_OUT 5


typedef struct s_fract
{
        void *mlx;
        void *window;
        void *image;
        int *color;
        float z_re;
        float z_im;
        float c_im;
        float c_re;
        float max_re;
        float min_re;
        float max_im;
        float min_im;
        int bit_per_pixel;
        int size_line;
        int endian;
        void *param;

}  t_fract;

int     ft_strcmp(char *str , char *checker);
int     ft_is_number(int n);
void    ft_putstr(char *str);
int     ft_skip(char *str, int *sign);
float   ft_atof(char *str);
void  draw_mandelbrot(t_fract *fract);
void    mandelbrot_set(t_fract *fract);
void julia_set(t_fract *fract , float c_re, float c_im);
int    save_exit(t_fract *fract);
void    mlx_startup(t_fract *fract);
void  set_data(t_fract *fract);
int    iteration_check(t_fract *fract);
void  put_pixel_to_img(t_fract *fract , int x , int y , int color);
int     mandelbrot_keybinds(int keycode, t_fract *fract);
int    mandelbrot_zoom(int code , int x , int y , t_fract *fract);
void  draw_julia(t_fract *fract);
int    julia_zoom(int code , int x , int y , t_fract *fract);
int     julia_keybinds(int keycode, t_fract *fract);
int  set_color(int iter);
void    ft_atol_exit();

#endif