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
CLIENT   = client

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c
NAME     = minitalk

LIBFT	 = libft.a
LIB		 = -L./libft -lft
BONUS	 = bonus

ifdef WITH_BONUS 
	SERVER_OBJ = ft_server_bonus.o
	CLIENT_OBJ = ft_client_bonus.o
else
	SERVER_OBJ = ft_server.o
	CLIENT_OBJ = ft_client.o
endif

all : $(NAME)

$(NAME)	: $(LIBFT) $(SERVER) $(CLIENT)

$(BONUS) : 
	@make WITH_BONUS=1 all
	
$(LIBFT)  :
	@make -C libft

$(SERVER) : $(SERVER_OBJ) 
	@$(CC) $< $(LIB) -o $@
	@echo "[SYSTEM] client program build complete\n"
	
$(CLIENT) : $(CLIENT_OBJ)
	@$(CC) $< $(LIB) -o $@
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
