/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:07:44 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/17 23:21:32 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	set_color(int iter)
{
	if (iter == MAX_ITER)
		return (0xFFD700);
	else
		return (0xF5F5F5 * iter);
}

int	ft_is_number(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_skip(char *str, int *sign)
{
	int	index;

	index = 0;
	while (str[index] >= 9 && str[index] <= 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			*sign *= -1;
		index++;
	}
	return (index);
}

float	ft_atof(char *str)
{
	float	number;
	int		index;
	int		sign;
	float	div;

	index = 0;
	sign = 1;
	number = 0;
	div = 0.1;
	index = ft_skip(str, &sign);
	while (str[index] && ft_is_number(str[index]) && str[index] != '.')
		number = (number * 10.0) + (str[index++] - 48);
	if (str[index] == '.')
		index++;
	while (str[index] && ft_is_number(str[index]))
	{
		number += (str[index] - '0') * div;
		div *= 0.1;
		index++;
	}
	if (str[index] && !ft_is_number(str[index]))
		ft_atof_exit();
	return (number * sign);
}
