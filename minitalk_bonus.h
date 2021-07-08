/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:22:46 by jealee            #+#    #+#             */
/*   Updated: 2021/07/08 13:22:50 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include "./libft/libft.h"
# define MSGBUFSIZE 2048

typedef	struct		s_message
{
	char			message[MSGBUFSIZE];
	unsigned int	top_bit;
	int				index;
	int				end;
	int				over;
}					t_message;

t_message			g_message;
#endif
