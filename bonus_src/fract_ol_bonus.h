/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:08:14 by keezgi            #+#    #+#             */
/*   Updated: 2025/04/18 01:00:49 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_BONUS_H
# define FRACT_OL_BONUS_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 400
# define HEIGHT 400
# define MAX_ITER 200
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define C 99

typedef struct s_fract
{
	void	*mlx;
	void	*window;
	void	*image;
	int		*color;
	float	z_re;
	float	z_im;
	float	c_im;
	float	c_re;
	float	max_re;
	float	min_re;
	float	max_im;
	float	min_im;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	void	*param;
	int		color_mode;
	float	factor;
	float	total_factor;
	float	re_shifting;
	float	im_shifting;

}			t_fract;

int			ft_strcmp(char *str, char *checker);
int			ft_is_number(int n);
void		ft_putstr(char *str);
int			ft_skip(char *str, int *sign);
float		ft_atof(char *str);
void		draw_mandelbrot(t_fract *fract);
void		mandelbrot_set(t_fract *fract);
void		julia_set(t_fract *fract, char *first, char *second);
int			save_exit(t_fract *fract);
void		mlx_startup(t_fract *fract);
void		set_data(t_fract *fract);
int			iteration_check(t_fract *fract);
void		put_pixel_to_img(t_fract *fract, int x, int y, int color);
int			mandelbrot_keybinds(int keycode, t_fract *fract);
int			mandelbrot_zoom(int code, int x, int y, t_fract *fract);
void		draw_julia(t_fract *fract);
int			julia_zoom(int code, int x, int y, t_fract *fract);
int			julia_keybinds(int keycode, t_fract *fract);
int			set_color(int iter, t_fract *fract);
void		ft_atof_exit(void);

#endif