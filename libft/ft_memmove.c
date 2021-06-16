/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:40:41 by jealee            #+#    #+#             */
/*   Updated: 2020/12/26 11:25:30 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned	char	*dt;
	unsigned	char	*sr;

	if ((!dst && !src) || len == 0)
		return (dst);
	dt = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (dst <= src)
	{
		index = 0;
		while (++index <= len)
			dt[index - 1] = sr[index - 1];
	}
	else
	{
		index = len;
		while (--index >= 1)
			dt[index] = sr[index];
		dt[index] = sr[index];
	}
	return (dst);
}
