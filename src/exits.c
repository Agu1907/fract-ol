/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:07:38 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 23:20:59 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	save_exit(t_fract *fract)
{
	if (fract->image)
		mlx_destroy_image(fract->mlx, fract->image);
	if (fract->window)
		mlx_destroy_window(fract->mlx, fract->window);
	if (fract->mlx)
		mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(0);
}

void	ft_atof_exit(void)
{
	ft_putstr("Invalid Number!");
	exit(1);
}
