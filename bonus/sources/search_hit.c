/*
** search_hit.c for function which will search the player hit from the click in /home/gaspar_q/rendu/semestre_2/Prog_Elem/CPE_2014_allum1/bonus/bonus_sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 18 16:01:40 2015 quentin gasparotto
** Last update Sun Feb 22 14:56:57 2015 quentin gasparotto
*/

#include "allum_1.h"

int	resolve_selection(t_system *sys, SDL_Rect *act_pos, int line)
{
  int	all;

  if (act_pos->y < sys->event.button.y &&
      act_pos->y + 100 > sys->event.button.y &&
      sys->allum_tab[1][line] > 0)
    {
      sys->line_hit = line;
      if (disp_empty(sys, sys->pos[line].x - sys->allum_tab[0][line] / 2 * 50,
		     line, sys->fire_allumet_sprite) == ERROR)
	return (ERROR);
      all = 0;
      while (act_pos->x < sys->event.button.x &&
	     act_pos->x <= (sys->pos[line].x +
			    sys->allum_tab[0][line] / 2 * 50) &&
	     all <= sys->allum_tab[0][line])
	{
	  act_pos->x = act_pos->x + 50;
	  if (all++ >= sys->allum_tab[0][line] - sys->allum_tab[1][line])
	    {
	      sys->allum_hit = sys->allum_hit + 1;
	      sys->selec = TRUE;
	    }
	}
    }
  return (CLEAN);
}

int	resolve_choose_button(t_system *sys)
{
  if (sys->selec)
    {
      if (SDL_BlitSurface(sys->every_button.choose.sprite, NULL,
			  sys->screen,
			  &sys->every_button.choose.pos) == ERROR)
	return (my_strerror(BLIT_ERR));
      if (SDL_BlitSurface(sys->every_button.choose.txt.disp_text, NULL,
			  sys->screen,
			  &sys->every_button.choose.txt.text_pos) == ERROR)
	return (my_strerror(BLIT_ERR));
    }
  else
    {
      if (SDL_BlitSurface(sys->hide_choose, NULL,
			  sys->screen, &sys->every_button.choose.pos) == ERROR)
	return (my_strerror(BLIT_ERR));
    }
  return (CLEAN);
}

int		search_allums(t_system *sys)
{
  int		line;
  SDL_Rect	act_pos;

  sys->selec = FALSE;
  line = -1;
  sys->line_hit = -1;
  sys->allum_hit = 0;
  while (++line < 4)
    {
      act_pos.y = sys->pos[line].y;
      act_pos.x = sys->pos[line].x - sys->allum_tab[0][line] / 2 * 50;
      if (resolve_selection(sys, &act_pos, line) == ERROR)
	return (ERROR);
      if (disp_empty(sys, act_pos.x, line, sys->allumet_sprite) == ERROR)
	return (ERROR);
    }
  if (resolve_choose_button(sys) == ERROR)
    return (ERROR);
  return (CLEAN);
}
