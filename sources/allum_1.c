/*
** allum_1.c for allum1 main function in /home/gaspar_q/rendu/semestre_2/Prog_Elem/Allum1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb  9 16:55:18 2015 quentin gasparotto
** Last update Sun Feb 15 16:32:58 2015 quentin gasparotto
*/

#include "../include/allum_1.h"

int	main(int argc, char **argv)
{
  char	*allum_tab;
  int	allum_nb;

  srandom(time(NULL));
  if (argc > 1)
    {
      allum_nb = my_getnbr(argv[1]);
      if (allum_nb > 4222)
	allum_nb = 4222;
    }
  else
    {
      allum_nb = 16;
    }
  if (get_allum_tab(&allum_nb, &allum_tab) == ERROR)
    return (ERROR);
  turn_to_turn(allum_tab, allum_nb, player_2());
  free(allum_tab);
  return (CLEAN);
}
