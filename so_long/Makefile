CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code
INCLUDES = -I ./mandatory/include -I ./mandatory/lib/MLX42/include

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LDFLAGS = -L ./mandatory/lib/MLX42/build -lmlx42 -lX11 -lXext -lm -pthread -lglfw -ldl
else ifeq ($(UNAME_S),Darwin)
	GLFW_PATH = $(shell brew --prefix glfw)
	LDFLAGS = -L ./mandatory/lib/MLX42/build -L $(GLFW_PATH)/lib -lmlx42 -lglfw -framework OpenGL -framework AppKit -ldl -pthread -lm
endif

# export LIBRARY_PATH=/Users/abenajib/.brew/opt/glfw/lib

SRC = ./mandatory/src/so_long.c \
		./mandatory/src/move.c \
		./mandatory/src/textures_functions.c \
		./mandatory/src/move_utils.c \
		./mandatory/src/map_parsing.c \
		./mandatory/src/map_checkers.c \
		./mandatory/src/map_checkers_2.c \
		./mandatory/src/map_checkers_3.c \
		./mandatory/src/game_init.c \
		./mandatory/ft_printf/ft_printf.c \
		./mandatory/ft_printf/ft_putchar_fd_p.c \
		./mandatory/ft_printf/ft_putnbr_fd_p.c \
		./mandatory/ft_printf/ft_putstr_fd_p.c \
		./mandatory/ft_printf/ft_puthex_fd_p.c \
		./mandatory/ft_printf/ft_putunint_fd_p.c \
		./mandatory/get_next_line/get_next_line.c \
		./mandatory/get_next_line/get_next_line_utils.c

BONUS_SRC = ./bonus/src_bonus/so_long_bonus.c \
		./bonus/src_bonus/move_bonus.c \
		./bonus/src_bonus/textures_functions_bonus.c \
		./bonus/src_bonus/move_utils_bonus.c \
		./bonus/src_bonus/map_parsing_bonus.c \
		./bonus/src_bonus/map_parsing_2_bonus.c \
		./bonus/src_bonus/map_checkers_bonus.c \
		./bonus/src_bonus/map_checkers_2_bonus.c \
		./bonus/src_bonus/map_checkers_3_bonus.c \
		./bonus/src_bonus/game_init_bonus.c \
		./mandatory/ft_printf/ft_printf.c \
		./mandatory/ft_printf/ft_putchar_fd_p.c \
		./mandatory/ft_printf/ft_putnbr_fd_p.c \
		./mandatory/ft_printf/ft_putstr_fd_p.c \
		./mandatory/ft_printf/ft_puthex_fd_p.c \
		./mandatory/ft_printf/ft_putunint_fd_p.c \
		./mandatory/get_next_line/get_next_line.c \
		./mandatory/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADER = ./mandatory/include/so_long.h
BONUS_HEADER = ./bonus/include_bonus/so_long_bonus.h

# Color codes for terminal output
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

TARGET = so_long
BONUS_TARGET = so_long_bonus

all: $(TARGET)

%.o: %.c $(HEADER) $(BONUS_HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJ) ./mandatory/libft/libft.a ./mandatory/ft_printf/libftprintf.a
	@$(CC) $(OBJ) ./mandatory/libft/libft.a ./mandatory/ft_printf/libftprintf.a $(LDFLAGS) -o $(TARGET)
	@echo "$(GREEN)______________	  ___   _____________________"
	@echo "$(GREEN)|     ||     |	  |  |   |     ||     ||     |"
	@echo "$(GREEN)|  ___!|  |  |	  |  |   |  |  ||     ||   __!"
	@echo "$(GREEN)!__   ||  |  |	  |  !___|  |  ||  |  ||  !  |"
	@echo "$(GREEN)|     ||  !  |____|     7|  !  ||  |  ||  !  |"
	@echo "$(GREEN)!_____!!_____!____!_____!!_____!!__!__!!_____!"
	@echo "$(GREEN)\n==The Makefile of [SO_LONG] has been compiled!==\n$(DEF_COLOR)"
	@echo "$(YELLOW)\n=> Usage: ./so_long <map.ber>\n$(DEF_COLOR)"

bonus: $(BONUS_TARGET)

$(BONUS_TARGET): $(BONUS_OBJ) ./mandatory/libft/libft.a ./mandatory/ft_printf/libftprintf.a
	@$(CC) $(BONUS_OBJ) ./mandatory/libft/libft.a ./mandatory/ft_printf/libftprintf.a $(LDFLAGS) -o $(BONUS_TARGET)
	@echo "$(GREEN)\n==The Makefile of [SO_LONG_BONUS] has been compiled!==\n$(DEF_COLOR)"
	@echo "$(YELLOW)\n=> Usage: ./so_long_bonus <map.ber>\n$(DEF_COLOR)"

clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)
	@make --silent -C ./mandatory/libft clean
	@make --silent -C ./mandatory/ft_printf clean

fclean: clean
	@rm -f $(TARGET)
	@rm -f $(BONUS_TARGET)
	@make --silent -C ./mandatory/libft fclean
	@make --silent -C ./mandatory/ft_printf fclean

re: fclean all

# Build MLX42 library
clone_mlx42:
	@git clone https://github.com/codam-coding-college/MLX42.git ./mandatory/lib/MLX42

mlx42:
	@echo "$(YELLOW)Building MLX42 library...$(DEF_COLOR)"
	@cmake ./mandatory/lib/MLX42 -B ./mandatory/lib/MLX42/build
	@make -C ./mandatory/lib/MLX42/build -j4

./mandatory/libft/libft.a:
	@echo "$(CYAN) Compiling...Please wait!\n"
	@make --silent -C ./mandatory/libft

./mandatory/ft_printf/libftprintf.a:
	@make --silent -C ./mandatory/ft_printf

.PHONY: all clean fclean re mlx42 libft ft_printf
