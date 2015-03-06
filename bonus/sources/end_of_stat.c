/*
** end_of_stat.c for end of stat in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Feb 15 17:38:56 2015 quentin gasparotto
** Last update Sun Feb 22 12:28:14 2015 quentin gasparotto
*/

#include "allum_1.h"

void	get_final_hit(char *allum_tab,
		      int *line,
		      int *allum,
		      char prob[3][1000])
{
  int	i;
  int	final;

  i = 0;
  final = -1;
  while (prob[2][i] != -1)
    {
      if (final == -1 || prob[2][i] > prob[2][final])
	final = i;
      i = i + 1;
    }
  if (final == -1 || prob[2][final] == -1)
    play_default(allum_tab, line, allum);
  else
    {
      *line = prob[0][final] + 1;
      *allum = prob[1][final];
      allum_tab[(*line) - 1] -= *allum;
    }
}
