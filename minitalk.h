/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:38:25 by jealee            #+#    #+#             */
/*   Updated: 2021/06/25 14:04:59 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "./libft/libft.h"
# define MSGBUFSIZE 2048

typedef	struct		s_message
{
	char			message[MSGBUFSIZE];
	unsigned int	top_bit;
	int				top_byte;
	int				end;
	int				over;
}					t_message;

t_message			g_message;
#endif
