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

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJF)
	@$(GCC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)*.o

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
