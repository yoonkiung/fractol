/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:55 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/07 14:27:57 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int count_w, int count_h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

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

int	julia(int count_w, int count_h, int iter)
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
