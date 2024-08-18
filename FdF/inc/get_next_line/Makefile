NAME		= gnl.a
INCLUDE		= get_next_line.h

OBJ_DIR		= obj/
GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

SRC 		= 	$(wildcard *.c)
OBJ 		= 	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(INCLUDE) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJF)
			@$(GCC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf *.o

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

test: re
	$(CC) $(NAME) test.c && ./a.out

.PHONY:		all clean fclean re norm