#include "fract_ol_bonus.h"

void  draw_mandelbrot(t_fract *fract)
{
      int x;
      int y;
      int iter;
      int color;

      color = 0;
      y = 0;
      while (y < HEIGHT)
      {
            x = 0;
            while (x < WIDTH)
            {
                  iter = 0;
                  fract->z_im = 0;
                  fract->z_re = 0;
                  fract->c_re = (fract->max_re - fract->min_re) * x / (double)WIDTH + fract->min_re;
                  fract->c_im = (fract->max_im - fract->min_im) * y / (double)HEIGHT + fract->min_im;
                  iter = iteration_check(fract);
                  color = set_color(iter , fract);
                  put_pixel_to_img(fract , x , y ,color);
                  x++;
            }
            y++;
      }
      mlx_put_image_to_window(fract->mlx , fract->window , fract->image , 0 , 0);
}
int    mandelbrot_zoom(int code , int x , int y , t_fract *fract)
{
        float	factor;
	float	mouse_re;
	float	mouse_im;

        if (code == ZOOM_IN)
                factor = 0.9;
        else if (code == ZOOM_OUT)
                factor = 1.1;
	else
		return (0);
	mouse_re = fract->min_re + (fract->max_re - fract->min_re) * x
		/ (double)WIDTH;
	mouse_im = fract->min_im + (fract->max_im - fract->min_im) * y
		/ (double)HEIGHT;
	fract->min_re = mouse_re + (fract->min_re - mouse_re) * factor;
	fract->max_re = mouse_re + (fract->max_re - mouse_re) * factor;
	fract->min_im = mouse_im + (fract->min_im - mouse_im) * factor;
	fract->max_im = mouse_im + (fract->max_im - mouse_im) * factor;
	draw_mandelbrot(fract);
	return (0);
}
int     mandelbrot_keybinds(int keycode, t_fract *fract)
{
        if (keycode == ESC)
                save_exit(fract);
        if (keycode == C)
        {
                if (fract->color_mode == 0)
                        fract->color_mode = 1;
                else
                        fract->color_mode = 0;
                draw_mandelbrot(fract);
        }
        if (keycode == UP)
                fract->max_im += 0.015;
        if (keycode == DOWN)
                fract->min_im  += 0.015;
        if (keycode == LEFT)
                fract->min_re += 0.015;
        if (keycode == RIGHT)
                fract->max_re += 0.015;
        draw_mandelbrot(fract);
        return (1);
}