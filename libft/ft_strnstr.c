/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:31:57 by jealee            #+#    #+#             */
/*   Updated: 2020/12/27 20:39:57 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	nlen;
	size_t	hlen;

	if (!*needle)
		return ((char *)haystack);
	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	if (!hlen || !len || nlen > len)
		return (NULL);
	index = 0;
	while (index + nlen <= len && index + nlen <= hlen)
	{
		if (!ft_strncmp(haystack + index, needle, nlen))
			return ((char *)(haystack + index));
		index++;
	}
	return (0);
}
