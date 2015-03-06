/*
** tab_info.c for get tab info in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Feb 15 16:56:48 2015 quentin gasparotto
** Last update Sun Feb 15 18:33:59 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

int	cpy_tab(char *tab, char *cpy)
{
  int	i;

  i = 0;
  while (tab[i] != -1)
    {
      cpy[i] = tab[i];
      i = i + 1;
    }
  cpy[i] = -1;
  return (CLEAN);
}

int	get_nb_of_allum(char *allum_tab)
{
  int	allum_nb;
  int	i;

  allum_nb = 0;
  i = 0;
  while (allum_tab[i] != -1)
    allum_nb += allum_tab[i++];
  return (allum_nb);
}
