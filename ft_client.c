/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:32:47 by jealee            #+#    #+#             */
/*   Updated: 2021/06/25 01:31:29 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_success(int signal)
{
	(void)signal;
	ft_putstr_fd("[SYS] server has received the data", 1);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_sendchar(int pid, unsigned char data)
{
	int	counter;

	counter = 1 << 15;
	while (counter)
	{
		if (data & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("[SYS] bad pid error\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("[SYS] bad pid error\n");
		}
		counter = counter >> 1;
		usleep(60);
	}
}

void	ft_handler(int pid, char *data)
{
	while (*data)
	{
		ft_sendchar(pid, *data);
		data++;
	}
	ft_sendchar(pid, *data);
	return ;
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("[USAGE] ./client [server-pid] [message]", 1);
		exit(0);
	}
	signal(SIGUSR1, ft_success);
	ft_handler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
