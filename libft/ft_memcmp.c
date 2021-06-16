/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:15:49 by jealee            #+#    #+#             */
/*   Updated: 2020/12/26 11:28:47 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	unsigned	char	s1val;
	unsigned	char	s2val;
	unsigned	char	*p;
	unsigned	char	*q;

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		s1val = p[index];
		s2val = q[index];
		if (s1val != s2val)
			return ((int)(s1val - s2val));
		index++;
	}
	return (0);
}
