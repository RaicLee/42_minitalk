/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 00:32:47 by jealee            #+#    #+#             */
/*   Updated: 2021/06/20 15:03:31 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void usage()
{
	write(1,"./client server-pid message\n",sizeof(char) * 28);
	exit(0);
}

int main(int argc, char** argv)
{
	if (argc != 3)
		usage();

}
