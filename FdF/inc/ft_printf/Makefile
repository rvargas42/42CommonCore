NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= ../libft/
SRC_DIR		= src/
OBJ_DIR		= obj/
GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

SRC 		= 	$(wildcard $(SRC_DIR)*.c)
OBJ 		= 	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ) $(LIBFT)libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(GCC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

test: re
	$(CC) $(NAME) test.c && ./a.out

.PHONY:		all clean fclean re norm
