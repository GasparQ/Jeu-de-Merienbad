/*
** turn_to_turn.c for la boucle inf in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Feb 19 19:48:32 2015 quentin gasparotto
** Last update Sun Feb 22 12:48:42 2015 quentin gasparotto
*/

#include "allum_1.h"

int	prepare_game(t_system *sys)
{
  if (SDL_BlitSurface(sys->cleaner, NULL, sys->screen,
		      &(sys->clean_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (disp_allumets(sys) == ERROR)
    return (ERROR);
  sys->disp = TRUE;
  sys->player = FIRST;
  if (SDL_BlitSurface(sys->turn_tell.player[sys->player].disp_text, NULL,
		      sys->screen,
		      &(sys->turn_tell.player[sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  return (CLEAN);
}

int	turn_to_turn(t_system *sys, int (*plyr_o_ia)(t_system *))
{
  if (prepare_game(sys) == ERROR)
    return (ERROR);
  while (sys->disp && sys->allum_nb > 0)
    {
      if (SDL_Flip(sys->screen) == ERROR)
	return (ERROR);
      if (sys->player)
	{
	  if (plyr_o_ia(sys) == ERROR)
	    return (ERROR);
	}
      else
	{
	  if (player_interface(sys) == ERROR)
	    return (ERROR);
	}
    }
  return (game_finish(sys));
}
