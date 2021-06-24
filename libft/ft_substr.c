/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:09:57 by jealee            #+#    #+#             */
/*   Updated: 2020/12/27 20:13:29 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	index;

	if (!s)
		return (NULL);
	index = ft_strlen(s);
	if (start >= index)
	{
		if (!(result = (char*)malloc(sizeof(char))))
			return (0);
		result[0] = '\0';
		return (result);
	}
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	index = 0;
	while (index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
