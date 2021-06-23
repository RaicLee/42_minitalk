# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 15:45:02 by jealee            #+#    #+#              #
#    Updated: 2021/06/23 15:36:25 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c
NAME     = minitalk
all : $(NAME)


$(NAME)	: $(SERVER) $(CLIENT)


$(SERVER) : ft_server.o ft_utils.o ft_itoa.o minitalk.h 
	@$(CC) ft_server.o ft_utils.o ft_itoa.o -o $@
	@echo "[SYSTEM] server program build complete\n"

$(CLIENT) : ft_client.o ft_utils.o minitalk.h
	@$(CC) ft_client.o ft_utils.o -o $@
	@echo "[SYSTEM] client program build complete"

%.o : %.c
	@$(CC) $(FLAGS) $< -o $@ -I. 

clean :
	@rm -f *.o
	@echo "[SYSTEM] obj file delete complete"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "[SYSTEM] server, client program delete complete"
re: fclean all
