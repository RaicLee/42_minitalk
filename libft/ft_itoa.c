/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:07:12 by jealee            #+#    #+#             */
/*   Updated: 2020/12/26 13:42:50 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				ft_intlen(unsigned int n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static	void			ft_reverse(char *str)
{
	size_t	length;
	size_t	index;
	char	temp;

	length = ft_strlen(str);
	index = 0;
	while (index < length / 2)
	{
		temp = str[index];
		str[index] = str[length - index - 1];
		str[length - index - 1] = temp;
		index++;
	}
}

static	unsigned int	ft_ui(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

char					*ft_itoa(int n)
{
	unsigned int	result;
	char			*ret;
	size_t			index;
	size_t			length;

	result = ft_ui(n);
	length = ft_intlen(result);
	if (n < 0)
		length++;
	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (0);
	index = 0;
	if (result == 0)
		ret[index++] = '0';
	while (result != 0)
	{
		ret[index++] = (result % 10) + '0';
		result = result / 10;
	}
	if (n < 0)
		ret[index++] = '-';
	ret[index] = '\0';
	ft_reverse(ret);
	return (ret);
}
