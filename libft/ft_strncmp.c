/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:18:46 by jealee            #+#    #+#             */
/*   Updated: 2020/12/25 16:52:32 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;

	index = 0;
	while (index < n)
	{
		if (*s1 == '\0' || *s2 == '\0' \
				|| (unsigned char)*s1 != (unsigned char)*s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		index++;
		s1++;
		s2++;
	}
	return (0);
}
