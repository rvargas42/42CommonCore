SERVER = server
CLIENT = client

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

GCC = gcc
FLAGS = -Wall -Wextra -Werror


all: $(SERVER) $(CLIENT)

clean:
	rm -f server client

NAME = .minitalk

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	$(GCC) $(SRC_DIR)server.c $(SRC_DIR)utils.c -o server #TODO: add flags
	echo "server compiled!"

$(CLIENT):
	$(GCC) $(SRC_DIR)client.c $(SRC_DIR)utils.c -o client #TODO: add flags
	echo "client compiled!\n"
