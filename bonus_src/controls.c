/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:08:02 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 21:24:40 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

void	mlx_startup(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
	{
		ft_putstr("Mlx initialization has been failed!");
		save_exit(fract);
	}
	fract->window = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "fract_ol");
	if (!fract->window)
	{
		ft_putstr("Window has not been created!");
		save_exit(fract);
	}
	fract->image = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->image)
	{
		ft_putstr("Failed to create new image!");
		save_exit(fract);
	}
}

int	ft_strcmp(char *str, char *checker)
{
	int	i;

	i = 0;
	while (checker[i] || str[i])
	{
		if (str[i] != checker[i])
			return (0);
		else
			i++;
	}
	return (1);
}
