/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:32:47 by jealee            #+#    #+#             */
/*   Updated: 2021/06/25 14:34:46 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_success(int signal)
{
	(void)signal;
	ft_putstr_fd("[ACK] server has received the data\n", 1);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_sendchar(int pid, unsigned char data)
{
	unsigned int	counter;

	counter = 1 << 15;
	while (counter)
	{
		if (data & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("[ERR] bad pid error\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("[ERR] bad pid error\n");
		}
		counter = counter >> 1;
		usleep(600);
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
		ft_putstr_fd("[USAGE] ./client [server-pid] [message]\n", 1);
		exit(0);
	}
	ft_putstr_fd("[SYS] Client with PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" starts to send data to server Pid: ", 1);
	ft_putnbr_fd(ft_atoi(argv[1]), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_success);
	ft_handler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
