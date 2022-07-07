/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:18:21 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/07 14:18:22 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
// # include "./mlx/mlx.h"
# include "mlx.h"
# include <math.h>
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define X_EVENT_MOUSE_PRESS 4
# define X_EVENT_MOUSE_MOTION 6
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define KEY_ESC 53
# define ITER_MAX 100

typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

// typedef struct s_zoom
// {
// 	double	max_width;
// 	double	min_width;
// 	double	max_height;
// 	double	min_width;
// }			t_zoom;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	// t_zoom		zoom;
}				t_mlx;

int		main(int ac, char **av);

int		window_init(t_mlx *mlx);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

int		color_set(int iter);

void	put_pixel(t_img *img, int flag);

int		key_press(int keycode);

int		close(int keycode);

int		mandelbrot(int count_w, int count_h, int iter);

int		julia(int count_w, int count_h, int iter);

#endif
