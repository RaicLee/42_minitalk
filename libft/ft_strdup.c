/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:22:27 by jealee            #+#    #+#             */
/*   Updated: 2020/12/28 10:59:45 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*result;

	length = ft_strlen(s1) + 1;
	result = (char *)malloc(sizeof(char) * length);
	if (!result)
		return (0);
	ft_memcpy(result, s1, length);
	return (result);
}
