/*
** player_interface.c for player interface while using in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Feb 19 19:52:46 2015 quentin gasparotto
** Last update Sun Feb 22 12:40:53 2015 quentin gasparotto
*/

#include "allum_1.h"

int	search_choose_button(t_system *sys)
{
  if (sys->event.button.x >= WIN_WDTH / 2 + 200 &&
      sys->event.button.x <= WIN_WDTH / 2 + 400)
    {
      if (sys->event.button.y >= WIN_HGHT / 2 + 250 &&
	  sys->event.button.y <= WIN_HGHT / 2 + 350)
	return (TRUE);
    }
  return (FALSE);
}

int	click_on_choose(t_system *sys)
{
  sys->allum_tab[1][sys->line_hit] -= sys->allum_hit;
  ++sys->line_hit;
  sys->allum_nb -= sys->allum_hit;
  sys->player = !(sys->player);
  if (SDL_BlitSurface(sys->hide_choose, NULL,
		      sys->screen,
		      &sys->every_button.choose.pos) == ERROR)
    return (my_strerror(BLIT_ERR));
  disp_allumets(sys);
  disp_hit(sys);
  sys->allum_hit = 0;
  sys->line_hit = -1;
  if (SDL_BlitSurface(sys->turn_tell.hide_player[!sys->player],
		      NULL, sys->screen,
		      &(sys->turn_tell.
			player[!sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  if (SDL_BlitSurface(sys->turn_tell.player[sys->player].disp_text,
		      NULL, sys->screen,
		      &(sys->turn_tell.
			player[sys->player].text_pos)) == ERROR)
    return (my_strerror(BLIT_ERR));
  sys->selec = FALSE;
  return (CLEAN);
}

int	player_interface(t_system *sys)
{
  if (SDL_WaitEvent(&(sys->event)) == 0)
    return (my_strerror(WAIT_ERR));
  if (sys->event.type == SDL_QUIT)
    sys->disp = FALSE;
  else if (sys->event.button.type == SDL_MOUSEBUTTONDOWN)
    {
      if (sys->selec)
	{
	  if (!search_choose_button(sys))
	    {
	      if (search_allums(sys) == ERROR)
		return (ERROR);
	    }
	  else
	    click_on_choose(sys);
	}
      else
	if (search_allums(sys) == ERROR)
	  return (ERROR);
    }
  else if (sys->event.type == SDL_KEYDOWN)
    if (sys->event.key.keysym.sym == SDLK_ESCAPE)
      sys->disp = FALSE;
  return (CLEAN);
}
