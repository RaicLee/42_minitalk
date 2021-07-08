/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:32:30 by jealee            #+#    #+#             */
/*   Updated: 2021/07/01 18:44:31 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit_activate(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (!g_message.top_bit)
	{
		g_message.top_bit = 1 << 15;
		g_message.index += 1;
	}
	g_message.message[g_message.index] += g_message.top_bit;
	g_message.top_bit >>= 1;
	if (g_message.index == MSGBUFSIZE - 1 && !g_message.top_bit)
		g_message.over = 1;
}

void	ft_bit_deactivate(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_message.top_bit)
	{
		g_message.top_bit = 1 << 15;
		g_message.index += 1;
	}
	g_message.top_bit >>= 1;
	if (g_message.index == MSGBUFSIZE - 1 && !g_message.top_bit)
		g_message.over = 1;
	else if (!g_message.message[g_message.index] && !g_message.top_bit)
	{
		g_message.end = 1;
		kill(info->si_pid, SIGUSR1);
	}
}

void	ft_print_and_check(struct sigaction *act, struct sigaction *deact)
{
	if (sigaction(SIGUSR1, act, NULL) != 0)
	{
		ft_putstr_fd("[ERROR] Signal Error\n", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, deact, NULL) != 0)
	{
		ft_putstr_fd("[ERROR] Signal Error\n", 2);
		exit(1);
	}
	ft_putstr_fd("[SYS] Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_bzero(g_message.message, MSGBUFSIZE);
	g_message.top_bit = 1 << 15;
	g_message.index = 0;
	g_message.end = 0;
	g_message.over = 0;
	return ;
}

void	ft_server_handler(void)
{
	while (1)
	{
		pause();
		if (g_message.end || g_message.over)
		{
			ft_putstr_fd(g_message.message, 1);
			ft_bzero(g_message.message, MSGBUFSIZE);
			g_message.top_bit = 1 << 15;
			g_message.index = 0;
			if (g_message.end)
				ft_putchar_fd('\n', 1);
			g_message.end = 0;
			g_message.over = 0;
		}
	}
}

int		main(void)
{
	struct sigaction activate;
	struct sigaction deactivate;

	activate.sa_sigaction = ft_bit_activate;
	activate.sa_flags = SA_SIGINFO;
	deactivate.sa_sigaction = ft_bit_deactivate;
	deactivate.sa_flags = SA_SIGINFO;
	ft_print_and_check(&activate, &deactivate);
	ft_server_handler();
	return (0);
}
