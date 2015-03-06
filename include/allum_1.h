/*
** allum_1.h for allum 1 header in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 16:55:39 2015 quentin gasparotto
** Last update Sun Feb 15 19:27:43 2015 quentin gasparotto
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

enum ERR_MACROS
  {
    CLEAN = 0,
    ERROR = -1
  };

enum PLAYERS
  {
    FIRST,
    SECOND
  };

# define MALLOC_ERR	"Malloc error\n"
# define BAD_ALLUM_NB	"Bad allum number\n"
# define READ_ERR	"Read error\n"

/*
** Prototypes
*/

/*
** tab_info.c
*/

int	cpy_tab(char *tab, char *cpy);
int	get_nb_of_allum(char *allum_tab);

/*
** end_of_stat.c
*/

void	get_final_hit(char *allum_tab, int *line, int *allum, char prob[3][1000]);

/*
** ia_montecarle.c
*/

int	monte_carle(char *allum_tab, int *line, int *allum);

/*
** ask_usr.c
*/

int	choose_usr();

/*
** ask_mode.c
*/

int	(*player_2())(char *, int *, int *);

/*
** artificial_intelligence.c
*/

void	play_default(char *allum_tab, int *line, int *allum);
int	ask_to_AI(char *allum_tab, int *line, int *allum);

/*
** usr_interface.c
*/

int	ask_usr(char *allum_tab, int *line, int *allum);

/*
** turn_to_turn.c
*/

void	turn_to_turn(char *allum_tab, int allum_nb, int (*plyr_o_IA)(char *, int *, int *));

/*
** show_wordtab.c
*/

void	show_wordtab(char **wt, int line, int allum);
void	free_wordtab(char **wordtab);
int	get_nb_of_word(char **wordtab);

/*
** get_allum.c
*/

int	get_allum_tab(int *allum_nb, char **allum_tab);

/*
** error.c
*/

int	check_nb(char *str);
int	my_strerror(char *str);
void	my_puterrstr(char *str);

/*
** lib
*/

int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_put_nbr(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);

#endif /* !ALLUM_H_ */
