/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:34:29 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/07 14:34:30 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
}

int	close(int keycode)
{
	exit(keycode);
}
