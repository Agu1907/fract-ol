/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:07:55 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 21:14:48 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_mandelbrot(t_fract *fract)
{
	int	x;
	int	y;
	int	iter;
	int	color;

	color = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			iter = 0;
			fract->z_im = 0;
			fract->z_re = 0;
			fract->c_re = ((fract->max_re - fract->min_re) * x / (double)WIDTH
					+ fract->min_re) + fract->re_shifting;
			fract->c_im = ((fract->max_im - fract->min_im) * y / (double)HEIGHT
					+ fract->min_im) + fract->im_shifting;
			iter = iteration_check(fract);
			color = set_color(iter);
			put_pixel_to_img(fract, x, y, color);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
}

int	mandelbrot_zoom(int code, int x, int y, t_fract *fract)
{
	float	mouse_re;
	float	mouse_im;

	if (code == ZOOM_IN)
		fract->factor = 0.9;
	else if (code == ZOOM_OUT)
		fract->factor = 1.1;
	else
		return (0);
	fract->total_factor = fract->total_factor * fract->factor;
	mouse_re = fract->min_re + (fract->max_re - fract->min_re) * x
		/ (double)WIDTH;
	mouse_im = fract->min_im + (fract->max_im - fract->min_im) * y
		/ (double)HEIGHT;
	fract->min_re = mouse_re + (fract->min_re - mouse_re) * fract->factor;
	fract->max_re = mouse_re + (fract->max_re - mouse_re) * fract->factor;
	fract->min_im = mouse_im + (fract->min_im - mouse_im) * fract->factor;
	fract->max_im = mouse_im + (fract->max_im - mouse_im) * fract->factor;
	draw_mandelbrot(fract);
	return (0);
}

int	mandelbrot_keybinds(int keycode, t_fract *fract)
{
	if (keycode == ESC)
		save_exit(fract);
	if (keycode == UP)
		fract->im_shifting += 0.015 * fract->total_factor;
	if (keycode == DOWN)
		fract->im_shifting -= 0.015 * fract->total_factor;
	if (keycode == LEFT)
		fract->re_shifting += 0.015 * fract->total_factor;
	if (keycode == RIGHT)
		fract->re_shifting -= 0.015 * fract->total_factor;
	draw_mandelbrot(fract);
	return (1);
}
