/*
** ask_usr.c for ask usr in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 14 19:51:21 2015 quentin gasparotto
** Last update Sat Feb 14 19:59:01 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

int	choose_usr()
{
  char	buff[4097];
  int	end;

  end = -1;
  while (end == -1)
    {
      my_putstr("Do you want to start first (y/n): ");
      if ((end = read(0, buff, 4096)) == ERROR)
	return (my_strerror(READ_ERR));
      if (buff[0] == 'y')
	return (FIRST);
      else if (buff[0] == 'n')
	return (SECOND);
      end = -1;
    }
  return (CLEAN);
}
