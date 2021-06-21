/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:32:30 by jealee            #+#    #+#             */
/*   Updated: 2021/06/21 17:14:50 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_pid()
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1,"[SYS] Server pid: ", sizeof(char) * 18);
	write(1,pid,ft_strlen(pid));
	write(1,"\n",1);
	free(pid);
}

int		main()
{
	ft_print_pid();
}
