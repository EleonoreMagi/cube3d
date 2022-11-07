NAME = ../cub3D


HEADERS = \
	cub_bonus.h \

SOURCES = \
	$(addprefix game/, \
		action_bonus.c \
		cast_rays_bonus.c \
		ft_button_bonus.c \
		ft_wasd1_bonus.c \
		paint_back_bonus.c \
		window1_bonus.c \
	) \
	$(addprefix parser/, \
		checker_bonus.c \
		parser_bonus.c \
		parser_utils_bonus.c \
		parser_utils2_bonus.c \
	) \
		$(addprefix main/, \
		main_bonus.c \
		init_bonus.c \
		free_bonus.c \
	) 

INC_DIR = ../includes
SRC_DIR = .

# SRC_DIR = srcs
OBJ_DIR = objs

INCS = $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

INCLUDES = -I$(INC_DIR) -I ../libft -I ../mlx

CC = gcc -g
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
MAKE_MLX = make -sC ../mlx
LINK_MLX = -L../mlx -lmlx -framework OpenGL -framework AppKit -lm -lz

MAKE_LIBFT = make -C ../libft
LINK_LIBFT = -L../libft -lft

all: init $(NAME)

init:
	@$(MAKE_LIBFT)
	@$(MAKE_MLX)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(INCLUDES) $(OBJS) $(LINK_LIBFT) $(LINK_MLX) -o $@
	@echo Done!

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	-$(RM) $(OBJ_DIR)
	-$(MAKE_MLX) clean  
	-$(MAKE_LIBFT) clean 

fclean:
	-$(RM) $(OBJ_DIR)
	-$(MAKE_MLX) clean
	-$(MAKE_LIBFT) fclean
	-$(RM) $(NAME)
	
re: fclean all

bonus:


.PHONY: all init clean flcean re
