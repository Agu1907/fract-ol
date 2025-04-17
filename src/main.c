/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:07:52 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 21:18:29 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_fract	fract;

	if (ac == 2 && ft_strcmp(av[1], "-help"))
	{
		ft_putstr("Best value's for Julia -> 0.355 0.355\n"
			"                         -0.4 0.61\n"
			"                         -0.70176 0.3842\n"
			"                         -0.4 0.6\n");
		exit(1);
	}
	if (ac == 2 && ft_strcmp(av[1], "Mandelbrot"))
		mandelbrot_set(&fract);
	else if (ac == 4 && ft_strcmp(av[1], "Julia"))
		julia_set(&fract, av[2], av[3]);
	else
	{
		ft_putstr("Wrong usage!\n"
			"Usage for Mandelbrot-> ./fract_ol Mandelbrot\n"
			"Usage for Julia -> ./fract_ol Julia <1> <2>\n"
			"(1 is reel value, 2 is imaginer value!)\n"
			"If you want more help, you can use -help\n");
	}
}
