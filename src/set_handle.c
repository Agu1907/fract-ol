#include "fract_ol.h"

void    mandelbrot_set(t_fract *fract)
{
        mlx_startup(fract);
        set_data(fract);
        draw_mandelbrot(fract);
        mlx_mouse_hook(fract->window , mandelbrot_zoom , fract);
        mlx_key_hook(fract->window , mandelbrot_keybinds, fract);
        mlx_hook(fract->window , 17 , 0 , save_exit , fract);
        mlx_loop(fract->mlx);
}
void julia_set(t_fract *fract , float c_re, float c_im)
{
        fract->c_re = c_re;
        fract->c_im = c_im;
        mlx_startup(fract);
        set_data(fract);
        draw_julia(fract);
        mlx_mouse_hook(fract->window , julia_zoom , fract);
        mlx_key_hook(fract->window , julia_keybinds, fract);
        mlx_hook(fract->window , 17 , 0 , save_exit , fract);
        mlx_loop(fract->mlx);
}