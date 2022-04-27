NAME_SRV = server
NAME_CLT = client
CC = gcc
FLAGS = -Wall -Werror -Wextra
SERVER = ./minitalk_utils.c ./server.c
OBJS = ${SERVER:.c=.o}
CLIENT = ./minitalk_utils.c ./client.c
OBJC = ${CLIENT:.c=.o}

.o.c:
				$(CC) $(FLAGS) -c $< -o $< -I./

$(NAME_SRV)	:	
				$(CC) $(FLAGS) -o $(NAME_SRV) $(SERVER)
				$(CC) $(FLAGS) -o $(NAME_CLT) $(CLIENT)

all		:	$(NAME_SRV)

re		:	clean all

clean	:
			rm -f server client
fclean	:	clean
			rm -f minitalk_utils.o client.o server.o

.PHONY	:	all clean fclean re $(NAME_SRV) $(NAME_CLT)

