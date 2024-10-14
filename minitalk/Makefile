NAME = minitalk
SERVER = server
CLIENT = client

SRC_DIR = src/
INC_DIR = inc/

SERVER_SRCs = $(SRC_DIR)server.c $(SRC_DIR)utils.c
CLIENT_SRCs = $(SRC_DIR)client.c $(SRC_DIR)utils.c

GCC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = $(INC_DIR)libft
LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF_DIR = $(INC_DIR)ft_printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

MYLIB = $(INC_DIR)mylib.a
OBJ_DIR = $(INC_DIR)obj/
LIBOBJS = $(OBJ_DIR)*.o
LIBFT_OBJS = $(OBJ_DIR)libft/*.o
FTPRINTF_OBJS = $(OBJ_DIR)ft_printf/*.o

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCs) $(MYLIB)
	$(GCC) $(FLAGS) $(SERVER_SRCs) $(MYLIB) -o $(SERVER)
	@echo "Server compiled!"

$(CLIENT): $(CLIENT_SRCs) $(MYLIB)
	$(GCC) $(FLAGS) $(CLIENT_SRCs) $(MYLIB) -o $(CLIENT)
	@echo "Client compiled!"

$(MYLIB): $(LIBFT) $(FTPRINTF) 
	@echo "Creating $(MYLIB)..."
	mkdir -p $(OBJ_DIR)
	ar rcs $(MYLIB) $(LIBFT_OBJS) $(FTPRINTF_OBJS)
	@echo "$(MYLIB) created!"


$(LIBFT): $(OBJDIR)
	@make -sC $(LIBFT_DIR)
	mkdir -p $(OBJ_DIR)libft
	cd $(OBJ_DIR)libft && ar -x ../../libft/libft.a

$(OBJDIR):
	mkdir -p $(OBJ_DIR)

$(FTPRINTF):
	@make -sC $(FTPRINTF_DIR)
	mkdir -p $(OBJ_DIR)ft_printf
	cd $(OBJ_DIR)ft_printf && ar -x ../../ft_printf/libftprintf.a

clean:
	rm -f $(SERVER) $(CLIENT) $(MYLIB)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FTPRINTF_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FTPRINTF_DIR)

re: fclean all
