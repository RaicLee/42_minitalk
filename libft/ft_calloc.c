/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:04:22 by jealee            #+#    #+#             */
/*   Updated: 2020/12/26 11:20:21 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned	char	*p;

	p = (unsigned char *)malloc(size * count);
	if (!p)
		return (0);
	ft_memset(p, 0, size * count);
	return ((void*)p);
}
