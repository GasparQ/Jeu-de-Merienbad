/*
** error.c for error gestion in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 17:40:43 2015 quentin gasparotto
** Last update Sat Feb 14 18:12:12 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

void	my_puterrchar(char c)
{
  write(2, &c, 1);
}

void	my_puterrstr(char *str)
{
  int	rank;

  rank = 0;
  while (str[rank] != '\0')
    {
      my_puterrchar(str[rank]);
      rank = rank + 1;
    }
}

int	my_strerror(char *error)
{
  my_puterrstr(error);
  return (ERROR);
}

int	check_nb(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
	{
	  my_putstr("Ce n'est pas un nombre\n");
	  return (0);
	}
      i = i + 1;
    }
  if (i == 0)
    return (0);
  return (1);
}
