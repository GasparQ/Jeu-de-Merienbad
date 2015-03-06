/*
** my_putstr.c for my put str in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 17:39:11 2015 quentin gasparotto
** Last update Sun Feb 22 12:26:45 2015 quentin gasparotto
*/

#include "allum_1.h"

void	my_putstr(char *str)
{
  int	rank;

  if (str != NULL)
    {
      rank = 0;
      while (str[rank] != '\0')
	{
	  my_putchar(str[rank]);
	  rank = rank + 1;
	}
    }
  else
    {
      my_putstr("Null");
    }
}
