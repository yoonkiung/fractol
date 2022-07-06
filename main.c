/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonkiung <kiyoon@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:26:00 by yoonkiung         #+#    #+#             */
/*   Updated: 2022/07/06 16:26:02 by yoonkiung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double x_new;
	double y;

	c_re = ((count_w - WIN_WIDTH / 2) * 3.0 / WIN_WIDTH) - 0.5;
	c_im = ((WIN_HEIGHT / 2) - count_h) * 2.0 / WIN_HEIGHT;
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int		julia(int count_w, int count_h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = -0.75;
	c_im = 0;
	x = ((count_w - WIN_WIDTH / 2) * 4.0 / WIN_WIDTH);
	y = ((WIN_HEIGHT / 2) - count_h) * 4.0 / WIN_HEIGHT;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int		window_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

int		color_set(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
	return (color);
}

void	put_pixel(t_img *img)
{
	int		iter;
    int		color;
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h <= WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w <= WIN_WIDTH)
		{
			iter = mandelbrot(count_w, count_h, 0);
			// iter = julia(count_w, count_h, 0);
			if (iter < ITER_MAX)
			{
         		   	color = color_set(iter);
        		   	my_mlx_pixel_put(img, count_w, count_h, color);
			}
            else
				my_mlx_pixel_put(img, count_w, count_h, 0x00000000);
		}
	}
}

int		key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	return(0);
}

int		close(int keycode)
{
	exit(keycode);
}

int		main(void)
{
	t_mlx	mlx;

	if (!window_init(&mlx))
		return (0);
	put_pixel(&mlx.img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, close, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);	
}
