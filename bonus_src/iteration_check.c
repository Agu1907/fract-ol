/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:08:20 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 21:25:07 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"
#include <math.h>

int	iteration_check(t_fract *fract)
{
	int		iter;
	float	temp;

	iter = 0;
	while ((fract->z_im * fract->z_im + fract->z_re * fract->z_re <= 4)
		&& (iter < MAX_ITER))
	{
		temp = fract->z_re * fract->z_re - fract->z_im * fract->z_im
			+ fract->c_re;
		fract->z_im = 2 * fract->z_re * fract->z_im + fract->c_im;
		fract->z_re = temp;
		iter++;
	}
	return (iter);
}

void	set_data(t_fract *fract)
{
	fract->color = (int *)mlx_get_data_addr(fract->image, &fract->bit_per_pixel,
			&fract->size_line, &fract->endian);
	fract->max_re = 1.0;
	fract->min_re = -2.0;
	fract->max_im = 1.5;
	fract->min_im = -1.5;
	fract->color_mode = 0;
	fract->im_shifting = 0;
	fract->re_shifting = 0;
	fract->total_factor = 1;
}

void	put_pixel_to_img(t_fract *fract, int x, int y, int color)
{
	int	index;

	index = y * WIDTH + x;
	fract->color[index] = color;
}
