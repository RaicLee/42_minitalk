# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 15:45:02 by jealee            #+#    #+#              #
#    Updated: 2021/06/17 00:35:37 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c

SV_SRC = ft_server.c
CL_SRC = ft_client.c
SRC = ft_utils.c

all : $(SERVER) $(CLIENT)

$(SERVER) : main_server.o error.o includes/minitalk.h
	@$(CC) main_server.o error.o -o $@
	@printf "\e[38;5;226m./$@ successfully build🥑\e[0m\n"

$(CLIENT) : main_client.o error.o includes/minitalk.h
	@$(CC) main_client.o error.o -o $@
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -o $@ -I. 

clean :
	@rm -f *.o
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re: fclean all
