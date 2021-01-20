# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 11:40:32 by ctaleb            #+#    #+#              #
#    Updated: 2021/01/20 11:43:21 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

AR = ar
ARFLAGS = rcs

INCS_PATH = .
LIB_PATH = libft/

SRCS = map_extractor.c\
		data_extractor.c\
		colour_utils.c\
		error_handler.c

OBJS = $(SRCS:.c=.o)
INCS = cube.h
LIB = libft.a
NAME = cube.a

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

.PHONY = all $(LIB_PATH)$(LIB) $(NAME) bonus clean fclean re project all42 42logo

all: project $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)$(LIB)
	@printf "$(MAGENTA)"
	cp $(LIB_PATH)$(LIB) $(NAME)
	@printf "$(DEFAULT)*********** $(CYAN)making $(NAME)$(DEFAULT) ***********\n"
	@printf "$(ORANGE)"
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "                 $(GREEN)[lib done]$(DEFAULT)                     \n\n"

bonus: all

$(LIB_PATH)$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c $(INCS)
	@printf "$(YELLOW)building$(DEFAULT)	%-20s	" "$@"
	@$(CC) $(CFLAGS) -I$(INCS_PATH) -o $@ -c $<
	@printf "$(GREEN)[ok]$(DEFAULT)\n"

clean:
	@printf "$(RED)"
	$(RM) $(OBJS) $(OBNS)
	@printf "$(DEFAULT)"
	@make -C $(LIB_PATH) clean

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
