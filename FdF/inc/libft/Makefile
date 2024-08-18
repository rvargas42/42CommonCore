SRC_DIR         = src/
OBJ_DIR         = obj/
INC_DIR         = inc/

SRCS            = $(wildcard $(SRC_DIR)*.c)
OBJS            = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
OBJF            = .cache_exists
INCLUDE         = $(INC_DIR)libft.h

B_SRCS          = $(wildcard $(SRC_DIR)*_bonus.c)
B_OBJS          = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(B_SRCS))

GCC              = gcc
CFLAGS          = -Wall -Werror -Wextra -I $(INC_DIR) -fPIC
AR              = ar rcs
RM              = rm -f

NAME            = libft.a

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(GCC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(B_OBJS)
	$(AR) $(NAME) $(B_OBJS)

.PHONY: all clean fclean re bonus
