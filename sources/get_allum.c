/*
** get_allum.c for function to get the allum tab in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 16:58:24 2015 quentin gasparotto
** Last update Thu Feb 12 13:03:06 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

int	fill_word_tab(char *allum_tab, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      allum_tab[i] = 1 + i * 2;
      i = i + 1;
    }
  return (CLEAN);
}

int	get_nb_of_line(int *allum_nb)
{
  int	u_n;
  int	final;
  int	n;

  u_n = -1;
  final = 0;
  n = 0;
  while (final < *allum_nb)
    {
      u_n = u_n + 2;
      n = n + 1;
      final = final + u_n;
    }
  if (final != *allum_nb)
    {
      *allum_nb = final - u_n;
      return (n - 1);
    }
  return (n);
}

int	get_allum_tab(int *allum_nb, char **allum_tab)
{
  int	n;

  n = get_nb_of_line(allum_nb);
  if (n <= 0)
    {
      return (my_strerror(BAD_ALLUM_NB));
    }
  if ((*allum_tab = malloc(n + 1)) == NULL)
    {
      return (my_strerror(MALLOC_ERR));
    }
  (*allum_tab)[n] = -1;
  fill_word_tab(*allum_tab, n);
  return (CLEAN);
}
