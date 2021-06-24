/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:21:07 by jealee            #+#    #+#             */
/*   Updated: 2020/12/23 15:11:13 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				index;
	unsigned	char	*p;
	unsigned	char	*q;

	index = 0;
	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	while (index < n)
	{
		p[index] = q[index];
		if (p[index] == (unsigned char)c)
			return ((void*)(p + index + 1));
		index++;
	}
	return (0);
}
