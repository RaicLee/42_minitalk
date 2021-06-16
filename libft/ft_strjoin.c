/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:57:40 by jealee            #+#    #+#             */
/*   Updated: 2020/12/25 20:13:21 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	totallength;

	if (!s1 || !s2)
		return (NULL);
	totallength = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * totallength);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, totallength);
	ft_strlcat(result, s2, totallength);
	return (result);
}
