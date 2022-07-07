/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:17:50 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/07 14:17:51 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	window_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!mlx->win)
		return (0);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img.img_ptr)
		return (0);
	mlx->img.data = mlx_get_data_addr \
		(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	if (!mlx->img.data)
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

int	color_set(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + \
		((int)(255.999 * g) << 8) + ((int)(255.999 * b));
	return (color);
}

void	put_pixel(t_img *img, int flag)
{
	int	iter;
	int	color;
	int	count_w;
	int	count_h;

	count_h = -1;
	while (++count_h <= WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w <= WIN_WIDTH)
		{
			if (flag == 0)
				iter = mandelbrot(count_w, count_h, 0);
			else
				iter = julia(count_w, count_h, 0);
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
#include <stdio.h>
int	mouse_pos(int x,int y)
{

	printf("Mouse moving in Win, at %dx%d.\n",x,y);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		flag;
	if (ac != 2 && (ft_strncmp(av[1], "mandelbort", 13) != 0 \
	|| ft_strncmp(av[1], "julia", 13) != 0))
	{
		ft_putstr_fd("wrong input\n \
		correct form is './fractol mandelbort' or'./fractol julia'\n", 1);
		return (0);
	}
	if (ft_strncmp(av[1], "mandelbort", 13) == 0)
		flag = 0;
	else
		flag = 1;
	if (!window_init(&mlx))
		return (0);
	put_pixel(&mlx.img, flag);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, close, 0);
	mlx_hook(mlx.win, X_EVENT_MOUSE_MOTION, 0, &mouse_pos, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
