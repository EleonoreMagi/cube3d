NAME = ../cub3D


HEADERS = \
	cub.h \

SOURCES = \
	$(addprefix game/, \
		action.c \
		cast_rays.c \
		ft_button.c \
		ft_wasd1.c \
		paint_back.c \
		window1.c \
	) \
	$(addprefix parser/, \
		checker.c \
		parser.c \
		parser_utils.c \
		parser_utils2.c \
	) \
		$(addprefix main/, \
		main.c \
		init.c \
		free.c \
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
