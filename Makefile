# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduchesn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:13:01 by gduchesn          #+#    #+#              #
#    Updated: 2023/02/09 22:17:12 by gduchesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

SRC =		new_pipex/main.c \
			new_pipex/ft_split.c \
			new_pipex/hub_pipe.c \
			new_pipex/access.c \
			new_pipex/pipex_utils.c

BN =		bonus/access_bonus.c \
			bonus/ft_split_bonus.c \
			bonus/hub_pipe_bonus.c \
			bonus/main_bonus.c \
			bonus/pipex_utils_bonus.c \
			bonus/limiter_finder_bonus.c \
			bonus/get_next_line/get_next_line_bonus.c \
			bonus/get_next_line/get_next_line_utils_bonus.c

OBJ = ${SRC:.c=.o}

OBJB = ${BN:.c=.o}

REMOVE = rm -f

.c.o:
		gcc -g -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: 	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJB)
				gcc -Wall -Wextra -Werror -o $(NAME) $(OBJB)

$(NAME):	$(OBJ)
				gcc -g -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	$(REMOVE) $(OBJ) $(OBJB)

fclean:	clean
	$(REMOVE) $(NAME)

re:	fclean all
