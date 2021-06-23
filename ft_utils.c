/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:31:59 by jealee            #+#    #+#             */
/*   Updated: 2021/06/23 22:40:12 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t		ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

static	int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			result;
	int			isminus;

	result = 0;
	isminus = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			isminus = 1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	if (isminus == 1)
		return (-1 * result);
	return (result);
}

static void	*ft_memset(void *b, int c, size_t len)
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

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
