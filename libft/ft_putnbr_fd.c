/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:49:02 by jealee            #+#    #+#             */
/*   Updated: 2020/12/23 01:57:26 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			result[30];
	int				index;
	unsigned int	value;

	index = 0;
	if (n == 0)
		write(fd, "0", sizeof(char));
	else
	{
		if (n < 0)
			value = n * -1;
		else
			value = n;
		while (value != 0)
		{
			result[index++] = (value % 10) + '0';
			value = value / 10;
		}
		if (n < 0)
			write(fd, "-", sizeof(char));
		while (--index >= 0)
		{
			write(fd, &result[index], sizeof(char));
		}
	}
}
