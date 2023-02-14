NAME = pipex

NAME_BONUS = pipex_bonus

SRC =		regular_pipex/main.c \
			regular_pipex/ft_split.c \
			regular_pipex/hub_pipe.c \
			regular_pipex/access.c \
			regular_pipex/pipex_utils.c

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

all: 	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJB)
				gcc -g -Wall -Wextra -Werror -o $(NAME_BONUS) $(OBJB)

$(NAME):	$(OBJ)
				gcc -g -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	$(REMOVE) $(OBJ) $(OBJB)

fclean:	clean
	$(REMOVE) $(NAME) $(NAME_BONUS)

re:	fclean all
