/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:16:03 by jealee            #+#    #+#             */
/*   Updated: 2020/12/25 20:11:45 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	while (dst[index] != '\0' && index < dstsize)
		index++;
	while (*src != '\0' && index + 1 < dstsize)
	{
		dst[index] = *src;
		index++;
		src++;
	}
	if (index < dstsize)
		dst[index] = '\0';
	while (*src != '\0')
	{
		index++;
		src++;
	}
	return (index);
}
