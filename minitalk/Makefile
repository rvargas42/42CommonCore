SERVER = server
CLIENT = client

SRC_DIR = src/
INC_DIR = inc/

SERVER_SRCs = $(SRC_DIR)server.c $(SRC_DIR)utils.c
CLIENT_SRCs = $(SRC_DIR)client.c $(SRC_DIR)utils.c

GCC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

NAME = .minitalk

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	$(GCC) $(SERVER_SRCs) -o server #TODO: add flags
	@echo "server compiled!"

$(CLIENT):
	$(GCC) $(CLIENT_SRCs) -o client #TODO: add flags
	@echo "client compiled!\n"


clean:
	rm -f server client

fclean: clean

re: fclean all