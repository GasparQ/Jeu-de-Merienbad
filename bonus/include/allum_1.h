/*
** allum_1.h for allum 1 header in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 16:55:39 2015 quentin gasparotto
** Last update Sun Feb 22 12:32:23 2015 quentin gasparotto
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# include "sdl_system.h"
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

# define EXIT_PROG	1

# define MALLOC_ERR	"Malloc error\n"
# define BAD_ALLUM_NB	"Bad allum number\n"
# define READ_ERR	"Read error\n"

# define COL(x) (x >= WIN_WDTH / 2 - 100 && x <= WIN_WDTH / 2 + 100) ? (1) : (0)
# define BT1(y) (y >= WIN_HGHT / 2 - 50 && y <= WIN_HGHT / 2 + 50) ? (1) : (0)
# define BT2(y) (y >= WIN_HGHT / 2 + 50 && y <= WIN_HGHT / 2 + 150) ? (1) : (0)
# define BT3(y) (y >= WIN_HGHT / 2 + 250 && y <= WIN_HGHT / 2 + 350) ? (1) : (0)

/*
** Prototypes
*/

/*
** flip_n_wait.c
*/

int	flip_n_wait(t_system *sys);

/*
** game_finish.c
*/

int	game_finish(t_system *sys);

/*
** disp_hit.c
*/

int	disp_hit(t_system *sys);

/*
** nbr_to_str.c
*/

char	*nbr_to_str(int nb);

/*
** resolve_player.c
*/

int	resolve_player(t_system *sys, int (*plyr_o_ai)(t_system *));

/*
** cpy_allum_tab.c
*/

void	cpy_allum_tab(char *ref_str, char *dest_str);

/*
** menu.c
*/

int	(*choose_mode(t_system *sys))(t_system *);

/*
** choose_ai.c
*/

int	(*choose_ai(t_system *sys))(t_system *);

/*
** ia_redirection.c
*/

int	montecarle(t_system *sys);
int	xor(t_system *sys);

/*
** player_interface.c
*/

int	player_interface(t_system *sys);


/*
** tab_info.c
*/

int	cpy_tab(char *tab, char *cpy);
int	get_nb_of_allum(char *allum_tab);

/*
** end_of_stat.c
*/

void	get_final_hit(char *allum_tab, int *line,
		      int *allum, char prob[3][1000]);

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

int	turn_to_turn(t_system *sys, int (*plyr_o_ia)(t_system *));

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
char	*my_strdup(char *str);

#endif /* !ALLUM_H_ */
