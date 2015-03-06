/*
** cpy_tab.c for cpy allum tab in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 21 12:31:34 2015 quentin gasparotto
** Last update Sat Feb 21 12:34:50 2015 quentin gasparotto
*/

#include "allum_1.h"

void	cpy_allum_tab(char *ref_tab, char *dest_tab)
{
  int	i;

  i = 0;
  while (ref_tab[i] != -1)
    {
      dest_tab[i] = ref_tab[i];
      i = i + 1;
    }
  dest_tab[i] = -1;
}
