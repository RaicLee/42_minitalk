# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 15:45:02 by jealee            #+#    #+#              #
#    Updated: 2021/06/25 23:50:00 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
SERVER_BONUS = bserver
CLIENT   = client
CLIENT_BONUS = bclient

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c
NAME     = minitalk

LIBFT	 = libft.a
LIB		 = -L./libft -lft
BONUS	 = bonus

all : $(NAME)

$(NAME)	: $(LIBFT) $(SERVER) $(CLIENT)

$(BONUS) : $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT)  :
	@make -C libft

$(SERVER) : ft_server.o 
	@$(CC) ft_server.o $(LIB) -o $@
	@echo "[SYSTEM] server program build complete\n"
$(SERVER_BONUS): ft_server_bonus.o
	@$(CC) ft_server_bonus.o $(LIB) -o server
	@echo "[BONUS SYSTEM] server program build complete\n"

$(CLIENT) : ft_client.o 
	@$(CC) ft_client.o $(LIB) -o $@
	@echo "[SYSTEM] client program build complete\n"
$(CLIENT_BONUS): ft_client_bonus.o
	@$(CC) ft_client_bonus.o $(LIB) -o client
	@echo "[BONUS SYSTEM] client program build complete\n"

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
