/*
** ask_mode.c for ask mode IA/play o play/play in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 14 18:43:26 2015 quentin gasparotto
** Last update Sun Feb 15 19:33:36 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

int	(*ia_choice())(char *, int *, int *)
{
  char	buf[4097];
  int	end;

  end = -1;
  while (end == -1)
    {
      my_putstr("Easy(1) or Hard(2): ");
      if ((end = read(0, buf, 4096)) == ERROR)
	{
	  my_strerror(READ_ERR);
	  return (NULL);
	}
      (buf[end - 1] == '\n' ? (buf[end - 1] = '\0') : (buf[end] = '\0'));
      if (end == 2)
	{
	  if (buf[0] == '1')
	    return (&monte_carle);
	  if (buf[0] == '2')
	    return (&ask_to_AI);
	}
      my_putstr("You have to choose between 1 and 2\n");
    }
  return (NULL);
}

int	(*player_2())(char *, int *, int *)
{
  char	buf[4097];
  int	end;

  end = -1;
  while (end == -1)
    {
      my_putstr("Player vs Player = 1 / Player vs IA = 2 : ");
      if ((end = read(0, buf, 4096)) == -1)
	{
	  my_strerror(READ_ERR);
	  return (NULL);
	}
      (buf[end - 1] == '\n' ? (buf[end - 1] = '\0') : (buf[end] = '\0'));
      if (check_nb(buf) == 1)
	{
	  end = my_getnbr(buf);
	  if (end == 1)
	    return (&ask_usr);
	  else if (end == 2)
	    return (ia_choice());
	}
      my_putstr("You have to choose between 1 and 2\n");
      end = -1;
    }
  return (NULL);
}

