/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:07:57 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 23:20:50 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mandelbrot_set(t_fract *fract)
{
	mlx_startup(fract);
	set_data(fract);
	draw_mandelbrot(fract);
	mlx_mouse_hook(fract->window, mandelbrot_zoom, fract);
	mlx_key_hook(fract->window, mandelbrot_keybinds, fract);
	mlx_hook(fract->window, 17, 0, save_exit, fract);
	mlx_loop(fract->mlx);
}

void	julia_set(t_fract *fract, char *first, char *second)
{
	float	c_re;
	float	c_im;

	c_re = ft_atof(first);
	if (c_re < -2.0 || c_re > 2.0)
		ft_atof_exit();
	c_im = ft_atof(second);
	if (c_im < -2.0 || c_im > 2.0)
		ft_atof_exit();
	fract->c_re = c_re;
	fract->c_im = c_im;
	mlx_startup(fract);
	set_data(fract);
	draw_julia(fract);
	mlx_mouse_hook(fract->window, julia_zoom, fract);
	mlx_key_hook(fract->window, julia_keybinds, fract);
	mlx_hook(fract->window, 17, 0, save_exit, fract);
	mlx_loop(fract->mlx);
}
