/*
** ia_montecarle.c for ia montecarle in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Feb 15 16:16:12 2015 quentin gasparotto
** Last update Sun Feb 22 12:27:25 2015 quentin gasparotto
*/

#include "allum_1.h"

void	stat_treatment(char stat[3][1000], int stat_game,
		       char prob[3][1000])
{
  int	prob_game;
  int	find;

  prob_game = 0;
  find = 0;
  while (!find)
    {
      if (prob[0][prob_game] == -1)
	find = 1;
      else if (prob[0][prob_game] == stat[0][stat_game] &&
	  prob[1][prob_game] == stat[1][stat_game])
	find = 1;
      else
	prob_game += 1;
    }
  if (prob[0][prob_game] != -1)
    prob[2][prob_game] += 1;
  else
    {
      prob[0][prob_game] = stat[0][stat_game];
      prob[1][prob_game] = stat[1][stat_game];
      prob[2][prob_game] = 0;
    }
}

void	init_prob(char prob[3][1000])
{
  int	i;

  i = 0;
  while (i < 100)
    {
      prob[0][i] = -1;
      prob[1][i] = -1;
      prob[2][i] = -1;
      i = i + 1;
    }
}

void	simul_hit(char *allum_tab, int len, char *line, char *allum)
{
  *line = -1;
  while (*line < 0)
    {
      *line = rand() % len;
      if (allum_tab[(int)(*line)] == 0)
	*line = -1;
    }
  *allum = 0;
  while (*allum < 1)
    *allum = rand() % (allum_tab[(int)(*line)] + 1);
}

void	simul_game(char *allum_tab, int len, char stat[3][1000], int game)
{
  char	line;
  char	allum;
  char	player;
  int	allum_nb;

  allum_nb = get_nb_of_allum(allum_tab);
  simul_hit(allum_tab, len, &stat[0][game], &stat[1][game]);
  allum_tab[(int)stat[0][game]] -= stat[1][game];
  allum_nb -= (int)stat[1][game];
  player = 0;
  while (allum_nb > 0)
    {
      simul_hit(allum_tab, len, &line, &allum);
      allum_tab[(int)line] -= allum;
      allum_nb -= allum;
      player = !player;
    }
  stat[2][game] = player;
}

int	monte_carle(char *allum_tab, int *line, int *allum)
{
  char	*cpy;
  char	stat[3][1000];
  char	prob[3][1000];
  int	nb_of_game;
  int	i;

  i = -1;
  while (allum_tab[++i] != -1);
  if ((cpy = malloc(i + 1)) == NULL)
    return (my_strerror(MALLOC_ERR));
  init_prob(prob);
  nb_of_game = 1000;
  while (nb_of_game > 0)
    {
      cpy_tab(allum_tab, cpy);
      simul_game(cpy, i, stat, 1000 - nb_of_game);
      if (stat[2][1000 - nb_of_game] == 1)
	stat_treatment(stat, 1000 - nb_of_game, prob);
      nb_of_game -= 1;
    }
  get_final_hit(allum_tab, line, allum, prob);
  free(cpy);
  return (CLEAN);
}
