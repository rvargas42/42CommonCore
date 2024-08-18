# Compiler and flags
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror

G =\033[0;32m
R =\033[0;31m
B =\033[0;34m

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
OBJF = .cache_exists
INC_DIR = inc/

# Libraries
GNL_DIR = $(INC_DIR)get_next_line
GNL = $(GNL_DIR)/gnl.a
GNL_OBJS = $(wildcard $(GNL_DIR)/obj/*.o)
LIBFT_DIR = $(INC_DIR)libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(wildcard $(LIBFT_DIR)/obj/*.o)
FT_PRINTF_DIR = $(INC_DIR)ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_OBJS = $(wildcard $(FT_PRINTF_DIR)/obj/*.o)
MLX_DIR = $(INC_DIR)minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
MYLIB = $(INC_DIR)myLib.a
#SOURCE
SRCs = 	$(wildcard $(SRC_DIR)*.c) \
		$(wildcard $(GNL)*.c)

OBJs = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCs)) # $(patsubst pattern,replacement,text)

# Target
NAME = fdf
INCLUDE = $(INC_DIR)fdf.h

all: $(NAME)

test: $(MYLIB) $(MLX)
	@$(COMPILER) $(SRCs) $(INCLUDE) $(MYLIB) $(MLX_LIB) -o $(NAME)

test_mem: fclean $(MYLIB)
	@$(COMPILER) $(SRCs) $(INCLUDE) $(MYLIB) -o $(NAME)
	@make -s verifyCompilation

$(NAME): $(MYLIB) $(OBJs) $(MLX)
	@gcc $(OBJs) $(INCLUDE) $(MYLIB) $(MLX_LIB) -o $(NAME)
	@make -s verifyCompilation

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(COMPILER) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(MYLIB): $(LIBFT) $(FT_PRINTF) $(GNL)
	@ar rcs $(MYLIB) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

$(LIBFT):
	@make -sC $(LIBFT_DIR)
$(FT_PRINTF):
	@make -sC $(FT_PRINTF_DIR)
$(GNL):
	@make -sC $(GNL_DIR)
$(MLX):
	@make -sC $(MLX_DIR)

verifyCompilation:
ifeq (, $(wildcard ./fdf.out))
	@echo "${G}$(NAME) Compiled!"
else
	@echo "$(NAME) not compiled :/ "
endif

clean:
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(FT_PRINTF_DIR)
	@make clean -sC $(MLX_DIR)
	@make clean -sC $(GNL_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning objects, libs and programs..."
	@make fclean -sC $(LIBFT_DIR)
	@make fclean -sC $(FT_PRINTF_DIR)
	@make fclean -sC $(GNL_DIR)
	@rm -f $(NAME)
	@rm -f *.o *.tgz
	@rm -f inc/*.a inc/*.gch 

re: fclean all

.PHONY: all fclean clean re
