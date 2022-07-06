/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:25:36 by kiyoon            #+#    #+#             */
/*   Updated: 2021/11/22 19:29:32 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*pb;
	size_t			allocate;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	pb = ptr;
	allocate = count * size;
	while (allocate-- > 0)
		*pb++ = 0;
	return (ptr);
}
