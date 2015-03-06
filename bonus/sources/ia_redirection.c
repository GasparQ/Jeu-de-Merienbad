/*
** ia_redirection.c for ia redirection in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 20 11:43:30 2015 quentin gasparotto
** Last update Sun Feb 22 12:19:12 2015 quentin gasparotto
*/

#include "allum_1.h"

int	montecarle(t_system *sys)
{
  monte_carle(sys->allum_tab[1], &(sys->line_hit), &(sys->allum_hit));
  sys->player = !(sys->player);
  sys->allum_nb -= sys->allum_hit;
  if (disp_allumets(sys) == ERROR)
    return (ERROR);
  if (SDL_BlitSurface(sys->turn_tell.hide_player[!sys->player], NULL,
		      sys->screen,
		      &(sys->turn_tell.player[!sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->turn_tell.player[sys->player].disp_text, NULL,
		      sys->screen,
		      &(sys->turn_tell.player[sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  disp_hit(sys);
  return (CLEAN);
}

int	xor(t_system *sys)
{
  ask_to_AI(sys->allum_tab[1], &(sys->line_hit), &(sys->allum_hit));
  sys->player = !(sys->player);
  sys->allum_nb -= sys->allum_hit;
  if (disp_allumets(sys) == ERROR)
    return (ERROR);
  if (SDL_BlitSurface(sys->turn_tell.hide_player[!sys->player], NULL,
		      sys->screen,
		      &(sys->turn_tell.player[!sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->turn_tell.player[sys->player].disp_text, NULL,
		      sys->screen,
		      &(sys->turn_tell.player[sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  disp_hit(sys);
  return (CLEAN);
}
