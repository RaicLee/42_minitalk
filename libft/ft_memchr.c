/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:56:44 by jealee            #+#    #+#             */
/*   Updated: 2020/12/26 11:27:28 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				index;
	unsigned	char	*p;

	index = 0;
	p = (unsigned char *)s;
	while (index < n)
	{
		if (p[index] == (unsigned char)c)
			return (p + index);
		index++;
	}
	return (0);
}
