# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 14:14:52 by ravargas          #+#    #+#              #
#    Updated: 2024/05/23 13:28:56 by ravargas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
LIBFT_DIR = $(INC_DIR)libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = $(INC_DIR)ft_printf
FT_PRINTF_OBJs = $(wildcard $(FT_PRINTF_DIR)/obj/*.o)
MYLIB = $(INC_DIR)myLib.a
#SOURCE
SRCs = 	$(wildcard $(SRC_DIR)*.c) \
		$(wildcard $(SRC_DIR)/utils/*c) \
		$(wildcard $(SRC_DIR)/instructions/*c) \
		$(wildcard $(SRC_DIR)/algorithm/*.c)

OBJs = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCs)) # $(patsubst pattern,replacement,text)

# Target
NAME = push_swap
INCLUDE = $(INC_DIR)push_swap.h

test: fclean $(LIBFT)
	@gcc $(SRCs) $(INCLUDE) $(LIBFT) -o $(NAME)
	@make -s executeTests

test_mem: fclean $(LIBFT)
	@gcc $(SRCs) $(INCLUDE) $(LIBFT) -o $(NAME)
	@make -s verifyCompilation
	@valgrind --leak-check=yes ./$(NAME) "1 2 3"

all: $(NAME) #Make files execute first rule by default

$(NAME): $(LIBFT) $(OBJs)
	@gcc $(FLAGS) $(OBJs) $(INCLUDE) $(LIBFT) -o $(NAME) 
	@make -s verifyCompilation

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(COMPILER) $(FLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(LIBFT): $(FT_PRINTF_OBJs)
	@echo "${B}Building needed libraries..."
	@make -sC $(LIBFT_DIR)
	@echo "${B}Linking libft.a and ft_printf objects"
	@make -sC $(FT_PRINTF_DIR)
	@ar rcs $(LIBFT) $(FT_PRINTF_OBJs)


verifyCompilation:
ifeq (, $(wildcard ./push_swap.out))
	@echo "${G}$(NAME) Compiled!"
else
	@echo "$(NAME) not compiled :/ " 
endif

executeTests: verifyCompilation
	@echo "${B}Executing basic test${B}"
	@chmod +x ./testing/basic_tests.sh
	@sh ./testing/basic_tests.sh

clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "${R}Cleaning objects and programs..."
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f *.o

re: fclean all

.PHONY: all fclean clean re