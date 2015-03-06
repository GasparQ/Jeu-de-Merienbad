/*
** main.c for main function in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 10:20:46 2015 quentin gasparotto
** Last update Sun Feb 22 14:56:34 2015 quentin gasparotto
*/

# include "allum_1.h"

int		main()
{
  t_system	sys;
  int		(*plyr_o_ai)(t_system *);

  if (init_sdl_system(&sys) == ERROR)
    return (ERROR);
  init_allum_pos(&sys);
  sys.allum_nb = 16;
  if (get_allum_tab(&(sys.allum_nb), &sys.allum_tab[0]) == ERROR)
    return (ERROR);
  if ((sys.allum_tab[1] = my_strdup(sys.allum_tab[0])) == NULL)
    return (ERROR);
  while ((plyr_o_ai = choose_mode(&sys)) != NULL)
    {
      if (resolve_player(&sys, plyr_o_ai) == ERROR)
	return (ERROR);
      if (turn_to_turn(&sys, plyr_o_ai) != CLEAN)
	break;
      sys.allum_nb = 16;
      cpy_allum_tab(sys.allum_tab[0], sys.allum_tab[1]);
    }
  quit_system(&sys);
  return (CLEAN);
}
