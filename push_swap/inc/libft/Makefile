SRC_DIR			= src
OBJ_DIR			= obj

SRCS			= $(wildcard  $(SRC_DIR)/*.c)
OBJS			= $(SRCS:.c=.o)

B_SRC			= $(wildcard $(SRC_DIR)/*_bonus.c)
B_OBJS			= $(B_SRC:.c=.o)

RM				= rm -f

NAME			= libft.a

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(B_OBJS)
				ar rcs $(NAME) $(B_OBJS)

.PHONY:			all clean fclean re bonus