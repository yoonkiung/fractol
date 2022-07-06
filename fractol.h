/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonkiung <kiyoon@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:11:28 by yoonkiung         #+#    #+#             */
/*   Updated: 2022/07/05 14:11:29 by yoonkiung        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include	<math.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define X_EVENT_MOUSE_PRESS 4
# define X_EVENT_MOUSE_MOTION 6
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

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

#endif