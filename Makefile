# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 15:45:02 by jealee            #+#    #+#              #
#    Updated: 2021/06/25 01:25:31 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c
NAME     = minitalk

LIBFT	 = libft.a
LIB		 = -L./libft -lft

all : $(NAME)

$(NAME)	: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT)  :
	@make -C libft

$(SERVER) : ft_server.o 
	@$(CC) ft_server.o $(LIB) -o $@
	@echo "[SYSTEM] server program build complete\n"

$(CLIENT) : ft_client.o 
	@$(CC) ft_client.o $(LIB) -o $@
	@echo "[SYSTEM] client program build complete\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -o $@ -I. 

clean :
	@make clean -C libft
	@rm -f *.o
	@echo "[SYSTEM] obj file delete complete\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@echo "[SYSTEM] server, client program delete complete\n"
re: fclean all
