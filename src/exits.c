#include "fract_ol.h"

int    save_exit(t_fract *fract)
{
        if (fract->image)
                mlx_destroy_image(fract->mlx , fract->image);
        if (fract->window)
                mlx_destroy_window(fract->mlx , fract->window);
        if (fract->mlx)
                mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        exit (0);
}
void    ft_atol_exit()
{
        ft_putstr("Invalid Number!");
        exit(1);
}