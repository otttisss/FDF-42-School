# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 21:53:20 by cmilagro          #+#    #+#              #
#    Updated: 2022/05/19 04:30:40 by cmilagro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

CC 			= gcc 
FLAGS 		= -Wall -Wextra -Werror -Ofast
LIBRARIES 	= -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES	= -I$(HEADERS_DIR) -I$(LIBFT_H) -I$(MINILIBX_H)

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= ./libft/
LIBFT_H		= $(LIBFT_DIR)

MINILIBX		= $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR	= ./minilibx/
MINILIBX_H		= $(MINILIBX_DIR)

HEADERS_LIST	= fdf.h\
				errors_ter.h\
				color.h\
				keys.h
HEADERS_DIR		= ./includes/
HEADERS			= $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_DIR		= ./sources/
SOURCES_LIST	= fdf.c read_map.c utils.c\
				  map_initing.c	 new_utils.c push_get_stack.c\
				  draw.c color.c utils_abs.c\
				  isometric.c controllers_utils.c keyboard_control.c\
				  mouse_control.c map_control.c menu_show.c\
				  utils_draw.c
				  
SOURCES			= $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR		= objects/
OBJECTS_LIST	= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS			= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
		@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
		@echo "\n$(NAME): $(GREEN)objects were created 🧪$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created 🪄🍳$(RESET)"

$(OBJECTS_DIR):
		@mkdir -p $(OBJECTS_DIR)
		@echo "$(NAME): $(GREEN)$(OBJECTS_DIR) was created 📦$(RESET)"

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
					@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
					@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
		@echo "$(NAME): $(GREEN)Creating $(LIBFT)...📙$(RESET)"
		@$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX): 
		@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...🗂$(RESET)"
		@$(MAKE) -sC $(MINILIBX_DIR)

clean: 
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)$(OBJECTS_DIR) was deleted🗑$(RESET)"
	@echo "$(NAME): $(RED)objects were deleted🗑$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted🗑$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted🗑$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted🗑$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
