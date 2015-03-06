##
## Makefile for allum 1 makefile in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1
## 
## Made by quentin gasparotto
## Login   <gaspar_q@epitech.net>
## 
## Started on  Mon Feb  9 16:52:47 2015 quentin gasparotto
## Last update Sun Feb 22 19:05:21 2015 quentin gasparotto
##

CC=	gcc

RM=	rm -f

NAME=	allum1

SRCS=	./sources/allum_1.c \
	./sources/get_allum.c \
	./sources/error.c \
	./sources/my_putstr.c \
	./sources/my_putchar.c \
	./sources/my_strlen.c \
	./sources/my_getnbr.c \
	./sources/my_put_nbr.c \
	./sources/turn_to_turn.c \
	./sources/usr_interface.c \
	./sources/artificial_intelligence.c \
	./sources/ask_mode.c \
	./sources/choose_usr.c \
	./sources/ia_montecarle.c \
	./sources/tab_info.c \
	./sources/end_of_stat.c \

OBJS=	$(SRCS:.c=.o)

CFLAGS=	-Wall -Wextra

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
