/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:32:47 by jealee            #+#    #+#             */
/*   Updated: 2021/06/23 15:48:11 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_success(int signal)
{
	(void)signal;
	write(1, "[SYSTEM] Data Received\n", 23);
}

void	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

void	ft_sendchar(int pid, unsigned char data)
{
	uint8_t	counter;

	counter = 1 << 6;
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
	int		pid;
	char	*message;

	if (argc != 3)
	{
		write(1, "[USAGE] ./client server-pid message\n", 36);
		exit(0);
	}
	signal(SIGUSR1, ft_success);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_handler(pid, message);
	return (0);
}
