/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:04:46 by jealee            #+#    #+#             */
/*   Updated: 2020/12/22 18:34:18 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				index;
	unsigned	char	*p;

	p = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		p[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
