##
## Makefile for compile sdl in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
## 
## Made by quentin gasparotto
## Login   <gaspar_q@epitech.net>
## 
## Started on  Wed Feb 18 11:11:10 2015 quentin gasparotto
## Last update Sun Feb 22 19:05:49 2015 quentin gasparotto
##

CC=	gcc

RM=	rm -f

NAME=	allum1

SRC=	./sources/main.c \
	./sources/init_allumets_pos.c \
	./sources/init_sdl_sys.c \
	./sources/disp_allumets.c \
	./sources/search_hit.c \
	./sources/quit_system.c \
	./sources/get_allum.c \
	./sources/error.c \
	./sources/my_putchar.c \
	./sources/my_putstr.c \
	./sources/my_strdup.c \
	./sources/player_interface.c \
	./sources/turn_to_turn.c \
	./sources/menu.c \
	./sources/choose_ai.c \
	./sources/ia_redirection.c \
	./sources/artificial_intelligence.c \
	./sources/ia_montecarle.c \
	./sources/tab_info.c \
	./sources/end_of_stat.c \
	./sources/cpy_allum_tab.c \
	./sources/resolve_player.c \
	./sources/nbr_to_str.c \
	./sources/disp_hit.c \
	./sources/game_finish.c \
	./sources/flip_n_wait.c \

OBJ=	$(SRC:.c=.o)

CFLAGS=	-Wall -Wextra -I./lib/SDL/include -I./include

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L../lib/SDL/lib -lSDL -lSDL_ttf

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
