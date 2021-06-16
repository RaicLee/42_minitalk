/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:05:58 by jealee            #+#    #+#             */
/*   Updated: 2020/12/23 15:42:50 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	val;

	val = (unsigned char)c;
	while (*s)
	{
		if (*s == val)
			return ((char*)s);
		s++;
	}
	if (!val)
		return ((char*)s);
	return (0);
}
