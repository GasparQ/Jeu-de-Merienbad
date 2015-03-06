/*
** artificial_intelligence.c for IA gestion in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb 10 17:27:44 2015 quentin gasparotto
** Last update Sun Feb 22 12:28:33 2015 quentin gasparotto
*/

#include "allum_1.h"

int	xor_my_tab(char *allum_tab, int line, int allum)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (allum_tab[i] != -1)
    {
      if (i == line)
	{
	  result = result ^ (allum_tab[i] - allum);
	}
      else
	{
	  result = result ^ allum_tab[i];
	}
      i = i + 1;
    }
  return (result);
}

int	get_condition_value(char *allum_tab, int line, int allum)
{
  int	i;

  i = 0;
  while (allum_tab[i] != -1)
    {
      if (i == line)
	{
	  if (allum_tab[i] - allum > 1)
	    return (0);
	}
      else
	{
	  if (allum_tab[i] > 1)
	    return (0);
	}
      i = i + 1;
    }
  return (1);
}

void	play_default(char *allum_tab, int *line, int *allum)
{
  int	my_line;

  my_line = 0;
  while (allum_tab[my_line] == 0 && allum_tab[my_line] != -1)
    my_line = my_line + 1;
  if (allum_tab[my_line] != -1)
    {
      allum_tab[my_line] = allum_tab[my_line] - 1;
      *allum = 1;
      *line = my_line + 1;
    }
}

int	ask_to_AI(char *allum_tab, int *line, int *allum)
{
  int	my_line;
  int	my_allum;
  int	condition;

  *line = -1;
  *allum = -1;
  my_line = -1;
  while (allum_tab[++my_line] != -1)
    {
      my_allum = 1;
      while (allum_tab[my_line] - my_allum >= 0)
	{
	  condition = get_condition_value(allum_tab, my_line, my_allum);
	  if (xor_my_tab(allum_tab, my_line, my_allum) == condition)
	    {
	      allum_tab[my_line] = allum_tab[my_line] - my_allum;
	      *allum = my_allum;
	      *line = my_line + 1;
	      return (CLEAN);
	    }
	  my_allum = my_allum + 1;
	}
    }
  play_default(allum_tab, line, allum);
  return (CLEAN);
}
