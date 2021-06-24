/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:00:29 by jealee            #+#    #+#             */
/*   Updated: 2020/12/23 16:56:13 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				index;
	unsigned	char	*p;
	unsigned	char	*q;

	if (!dst && !src)
		return (dst);
	index = 0;
	p = (unsigned char*)src;
	q = (unsigned char*)dst;
	while (index < n)
	{
		q[index] = p[index];
		index++;
	}
	return (dst);
}
