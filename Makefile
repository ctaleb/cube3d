# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 11:40:32 by ctaleb            #+#    #+#              #
#    Updated: 2021/05/08 15:44:25 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

MAP = src/maps/level0.cub
SAVE = --save

CC = gcc
CFLAGS = -O3 -fno-builtin -g3 -Wall -Wextra -Werror #-fsanitize=address
RM = rm -f

AR = ar
ARFLAGS = rcs

INCS_PATH = inc/
LIB_PATH = libft/

SRC_DIR = ./src/

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit
MLX_PATH = minilibx/

INCS = cube.h

SRC = main.c\
		map_extractor.c\
		data_extractor.c\
		colour_utils.c\
		map_utils.c\
		math_utils.c\
		converter.c\
		map_init.c\
		mlx_init.c\
		texture_init.c\
		sprite_init.c\
		frame_gen.c\
		data_init.c\
		minimap.c\
		movement.c\
		events.c\
		fov.c\
		fov_utils.c\
		wallcheck.c\
		camera.c\
		raycaster.c\
		spriter.c\
		sprite_utils.c\
		sprite_calcs.c\
		error_handler.c\
		freedom.c\
		bitmapping.c\
		parser.c\
		hud.c\
		data_reader.c\
		doors.c\
		movement_utils.c\
		events_utils.c\
		music.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

LIB = libft.a
MLIB = libmlx.a
NAME = cub3D

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
MAGENTA = \033[35m
CYAN = \033[36m
ORANGE = \033[38:5:208m
WHITE = \033[38:5:15m
BRCYAN = \033[38:5:14m
DEFAULT = \033[0m

PROJECT = CUBE3D
DELAY = 0.02

.PHONY = all $(LIB_PATH)$(LIB) $(NAME) bonus clean fclean re project all42 42logo run

%.o: %.c $(INCS_PATH)$(INCS)
	@printf "$(YELLOW)building$(DEFAULT)	%-20s	" "$@"
	@$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<
	@printf "$(GREEN)[ok]$(DEFAULT)\n"

all: project $(NAME)

$(NAME): $(MLX_PATH)$(MLIB) $(OBJS) $(LIB_PATH)$(LIB)
	@printf "$(MAGENTA)"
	@printf "$(DEFAULT)*************** $(CYAN)making $(NAME)$(DEFAULT) ***************\n"
	@printf "$(YELLOW)building$(DEFAULT)	%-20s	" "$(NAME)"
	@$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS) $(LIB_PATH)$(LIB) $(MLX)
	@printf "$(GREEN)[ok]$(DEFAULT)\n"
	@printf "                $(GREEN)[exec done]$(DEFAULT)                    \n\n"

bonus: all

$(LIB_PATH)$(LIB):
	@make -C $(LIB_PATH)

$(MLX_PATH)$(MLIB):
	@make -C $(MLX_PATH)

run: all
	./cub3D $(MAP)

save: all
	./cub3D $(MAP) $(SAVE)

clean:
	@printf "$(RED)"
	$(RM) $(OBJS) $(OBNS)
	@printf "$(DEFAULT)"
	@make -C $(LIB_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@printf "$(RED)"
	$(RM) $(NAME)
	@printf "$(DEFAULT)"
	@make -C $(LIB_PATH) fclean

re: fclean all

project:
	@printf "$(DEFAULT)********************************************\n"
	@printf "                    $(PROJECT)                   "
	@printf "$(DEFAULT)\n********************************************\n"

all42: fclean 42logo project all bonus

42logo:
	@printf "$(BRCYAN)"
	@clear
	@printf "$(BRCYAN):\n:\n \n \n \n \n$(WHITE)r\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)::\n+:\n  \n  \n  \n  \n$(WHITE)fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN):::\n:+:\n+  \n   \n   \n   \n$(WHITE).fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)::::\n :+:\n:+  \n    \n    \n    \n$(WHITE)n.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN):::::\n  :+:\n+:+  \n     \n     \n     \n$(WHITE)on.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)::::::\n   :+:\n +:+  \n+     \n      \n      \n$(WHITE)yon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN):::::::\n    :+:\n  +:+  \n#+     \n       \n       \n$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)::::::::\n:    :+:\n   +:+  \n+#+     \n        \n        \n#$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN) ::::::::\n+:    :+:\n    +:+  \n +#+     \n+        \n         \n##$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)  ::::::::\n:+:    :+:\n     +:+  \n  +#+     \n#+        \n          \n###$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)   ::::::::\n :+:    :+:\n      +:+  \n   +#+     \n+#+        \n#          \n####$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)    ::::::::\n  :+:    :+:\n       +:+  \n    +#+     \n +#+        \n+#          \n#####$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)     ::::::::\n   :+:    :+:\n        +:+  \n     +#+     \n  +#+        \n#+#          \n######$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)      ::::::::\n    :+:    :+:\n         +:+  \n      +#+     \n   +#+        \n #+#          \n#######$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN):      ::::::::\n     :+:    :+:\n+         +:+  \n       +#+     \n+   +#+        \n  #+#          \n########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)::      ::::::::\n      :+:    :+:\n:+         +:+  \n+       +#+     \n#+   +#+        \n   #+#          \n ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN):::      ::::::::\n:      :+:    :+:\n+:+         +:+  \n:+       +#+     \n+#+   +#+        \n    #+#          \n  ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN) :::      ::::::::\n+:      :+:    :+:\n +:+         +:+  \n+:+       +#+     \n#+#+   +#+        \n#    #+#          \n   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)  :::      ::::::::\n:+:      :+:    :+:\n+ +:+         +:+  \n +:+       +#+     \n+#+#+   +#+        \n+#    #+#          \n#   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)   :::      ::::::::\n :+:      :+:    :+:\n:+ +:+         +:+  \n  +:+       +#+     \n#+#+#+   +#+        \n#+#    #+#          \n##   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)    :::      ::::::::\n  :+:      :+:    :+:\n+:+ +:+         +:+  \n+  +:+       +#+     \n+#+#+#+   +#+        \n #+#    #+#          \n###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)     :::      ::::::::\n   :+:      :+:    :+:\n +:+ +:+         +:+  \n#+  +:+       +#+     \n#+#+#+#+   +#+        \n  #+#    #+#          \n ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)      :::      ::::::::\n    :+:      :+:    :+:\n  +:+ +:+         +:+  \n+#+  +:+       +#+     \n+#+#+#+#+   +#+        \n   #+#    #+#          \n  ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)       :::      ::::::::\n     :+:      :+:    :+:\n   +:+ +:+         +:+  \n +#+  +:+       +#+     \n#+#+#+#+#+   +#+        \n    #+#    #+#          \n   ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)        :::      ::::::::\n      :+:      :+:    :+:\n    +:+ +:+         +:+  \n  +#+  +:+       +#+     \n+#+#+#+#+#+   +#+        \n     #+#    #+#          \n    ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)         :::      ::::::::\n       :+:      :+:    :+:\n     +:+ +:+         +:+  \n   +#+  +:+       +#+     \n +#+#+#+#+#+   +#+        \n      #+#    #+#          \n     ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)          :::      ::::::::\n        :+:      :+:    :+:\n      +:+ +:+         +:+  \n    +#+  +:+       +#+     \n  +#+#+#+#+#+   +#+        \n       #+#    #+#          \n      ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)           :::      ::::::::\n         :+:      :+:    :+:\n       +:+ +:+         +:+  \n     +#+  +:+       +#+     \n   +#+#+#+#+#+   +#+        \n        #+#    #+#          \n       ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)            :::      ::::::::\n          :+:      :+:    :+:\n        +:+ +:+         +:+  \n      +#+  +:+       +#+     \n    +#+#+#+#+#+   +#+        \n         #+#    #+#          \n        ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)             :::      ::::::::\n           :+:      :+:    :+:\n         +:+ +:+         +:+  \n       +#+  +:+       +#+     \n     +#+#+#+#+#+   +#+        \n          #+#    #+#          \n         ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)              :::      ::::::::\n            :+:      :+:    :+:\n          +:+ +:+         +:+  \n        +#+  +:+       +#+     \n      +#+#+#+#+#+   +#+        \n           #+#    #+#          \n          ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)               :::      ::::::::\n             :+:      :+:    :+:\n           +:+ +:+         +:+  \n         +#+  +:+       +#+     \n       +#+#+#+#+#+   +#+        \n            #+#    #+#          \n           ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)                :::      ::::::::\n              :+:      :+:    :+:\n            +:+ +:+         +:+  \n          +#+  +:+       +#+     \n        +#+#+#+#+#+   +#+        \n             #+#    #+#          \n            ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)                 :::      ::::::::\n               :+:      :+:    :+:\n             +:+ +:+         +:+  \n           +#+  +:+       +#+     \n         +#+#+#+#+#+   +#+        \n              #+#    #+#          \n             ###   ########$(WHITE)lyon.fr\n"
	@sleep $(DELAY)
	@clear
	@printf "$(BRCYAN)                  :::      ::::::::\n                :+:      :+:    :+:\n              +:+ +:+         +:+  \n            +#+  +:+       +#+     \n          +#+#+#+#+#+   +#+        \n               #+#    #+#          \n              ###   ########$(WHITE)lyon.fr\n\n"
	@sleep $(DELAY)
