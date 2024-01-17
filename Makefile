NAME = cub3d

CC = gcc
UNAME = $(shell uname)
CFLAGS = -Wall -Werror -Wextra
LFLAGS = $(LIBMLX_DIR)/libmlx42.a
INC = -I $(INC_DIR) -I $(LIBFT_DIR)/inc -I $(LIBMLX_DIR)/include/MLX42
LIBS = $(LIBFT_DIR)/libft.a $(LIBMLX_DIR)/libmlx42.a
RM = rm -rf

ifeq ($(UNAME), Darwin)
# mac
	LFLAGS += -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
else ifeq ($(UNAME), Linux)
# Linux
	LFLAGS += -ldl -lglfw -pthread -lm
else
	@echo "$(R)[The program is only available for Linux and MacOS]\n$(END)"
endif

SRCS = $(SRC_DIR)/main.c\

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#########################  directorios(rutas)  #################################
# ./
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include
# ./lib
LIBFT_DIR = lib/libft
LIBMLX_DIR = lib/libmlx

#########################  Colores  ############################################
RED		= \033[31;1m
GREEN	= \033[32;1m
CIAN	= \033[36m
BLUE	= \033[1;38;5;27m
YELLOW	= \033[33m;1m
WHITE	= \033[37;1m
U_LINE	= \033[4m
END 	= \033[0m

#########################  ARGS  ###############################################
all: $(NAME)

bonus: all

show:
	@printf "UNAME	: $(UNAME)\n"
	@printf "NAME  	: $(NAME)\n"
	@printf "CC	: $(CC)\n"
	@printf "CFLAGS	: $(CFLAGS)\n"
	@printf "LFLAGS	: $(LFLAGS)\n"
	@printf "SRCS	:$(addprefix \n\t , $(notdir $(SRCS)))\n"$

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(LIBMLX_DIR)
	@echo "$(GREEN)[Cleaned $(CIAN) '$(NAME) objects' $(GREEN)successfully]$(END)"

fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@make fclean -sC $(LIBMLX_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)[Removed $(CIAN)'$(NAME)' $(GREEN)successfully]$(END)"

re: fclean all

#########################  Normas  #############################################
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/cub3d.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
		@echo "$(BLUE)CUB3D Compiling:$(END) $(notdir $<)"

$(NAME): $(OBJS)
	@echo "\n$(WHITE)$(U_LINE)  CUB3D: Compiled $(RESET)\n"
	@make -sC $(LIBMLX_DIR)
	@make -sC $(LIBFT_DIR)
	@$(CC) $(OBJS) $(LIBS) $(CFLAGS) $(LFLAGS) $(INC) -o $(NAME)
	@echo "\n$(GREEN)[Compiled $(CIAN) $@ $(GREEN)successfully]\n$(END)"

.PHONY: all bonus show clean fclean re
